// #pragma once
//
// // =======================================================
// //  Mongo.hpp - Header-only MongoDB wrapper
// //  Dependency: libmongoc, libbson
// // =======================================================
//
// #include <mongoc/mongoc.h>
// #include <bson/bson.h>
//
// #include <string>
// #include <stdexcept>
//
// namespace mongo
// {
//
//     // =======================================================
//     // Exception
//     // =======================================================
//
//     class MongoException : public std::runtime_error
//     {
//     public:
//         explicit MongoException(const std::string& msg)
//             : std::runtime_error(msg) {}
//     };
//
//     // =======================================================
//     // Global init / cleanup (process-level)
//     // =======================================================
//
//     class MongoGlobal
//     {
//     public:
//         MongoGlobal()
//         {
//             mongoc_init();
//         }
//
//         ~MongoGlobal()
//         {
//             mongoc_cleanup();
//         }
//
//         MongoGlobal(const MongoGlobal&) = delete;
//         MongoGlobal& operator=(const MongoGlobal&) = delete;
//     };
//
//     // =======================================================
//     // Mongo Client Pool (thread-safe)
//     // =======================================================
//
//     class MongoClientPool
//     {
//     public:
//         explicit MongoClientPool(const std::string& uri)
//         {
//             mongoc_uri_t* u = mongoc_uri_new(uri.c_str());
//             if (!u)
//                 throw MongoException("Invalid MongoDB URI");
//
//             pool_ = mongoc_client_pool_new(u);
//             mongoc_uri_destroy(u);
//
//             if (!pool_)
//                 throw MongoException("Failed to create MongoClientPool");
//         }
//
//         ~MongoClientPool()
//         {
//             if (pool_)
//                 mongoc_client_pool_destroy(pool_);
//         }
//
//         mongoc_client_t* pop()
//         {
//             return mongoc_client_pool_pop(pool_);
//         }
//
//         void push(mongoc_client_t* client)
//         {
//             mongoc_client_pool_push(pool_, client);
//         }
//
//         MongoClientPool(const MongoClientPool&) = delete;
//         MongoClientPool& operator=(const MongoClientPool&) = delete;
//
//     private:
//         mongoc_client_pool_t* pool_ = nullptr;
//     };
//
//     // =======================================================
//     // RAII client guard (one per thread / task)
//     // =======================================================
//
//     class MongoClientGuard
//     {
//     public:
//         explicit MongoClientGuard(MongoClientPool& pool)
//             : pool_(pool)
//             , client_(pool_.pop())
//         {
//             if (!client_)
//                 throw MongoException("Failed to pop Mongo client");
//         }
//
//         ~MongoClientGuard()
//         {
//             if (client_)
//                 pool_.push(client_);
//         }
//
//         mongoc_client_t* get() const
//         {
//             return client_;
//         }
//
//         MongoClientGuard(const MongoClientGuard&) = delete;
//         MongoClientGuard& operator=(const MongoClientGuard&) = delete;
//
//     private:
//         MongoClientPool& pool_;
//         mongoc_client_t* client_;
//     };
//
//     // =======================================================
//     // Cursor wrapper
//     // =======================================================
//
//     class MongoCursor
//     {
//     public:
//         explicit MongoCursor(mongoc_cursor_t* cursor)
//             : cursor_(cursor)
//         {
//         }
//
//         ~MongoCursor()
//         {
//             if (cursor_)
//                 mongoc_cursor_destroy(cursor_);
//         }
//
//         bool next(const bson_t** out)
//         {
//             return mongoc_cursor_next(cursor_, out);
//         }
//
//         MongoCursor(const MongoCursor&) = delete;
//         MongoCursor& operator=(const MongoCursor&) = delete;
//
//     private:
//         mongoc_cursor_t* cursor_ = nullptr;
//     };
//
//     // =======================================================
//     // Collection wrapper (NOT thread-safe, stack use only)
//     // =======================================================
//
//     class MongoCollection
//     {
//     public:
//         MongoCollection(mongoc_client_t* client,
//             const std::string& db,
//             const std::string& coll)
//         {
//             coll_ = mongoc_client_get_collection(
//                 client, db.c_str(), coll.c_str());
//
//             if (!coll_)
//                 throw MongoException("Failed to get collection");
//         }
//
//         ~MongoCollection()
//         {
//             if (coll_)
//                 mongoc_collection_destroy(coll_);
//         }
//
//         // ---------------- INSERT ----------------
//
//         void insert(const bson_t* doc)
//         {
//             bson_error_t err;
//             if (!mongoc_collection_insert_one(
//                 coll_, doc, nullptr, nullptr, &err))
//             {
//                 throw MongoException(err.message);
//             }
//         }
//
//         // ---------------- FIND ----------------
//
//         MongoCursor find(const bson_t* query,
//             const bson_t* opts = nullptr)
//         {
//             mongoc_cursor_t* cursor =
//                 mongoc_collection_find_with_opts(
//                     coll_, query, opts, nullptr);
//
//             return MongoCursor(cursor);
//         }
//
//         // ---------------- DELETE ----------------
//
//         void remove(const bson_t* query)
//         {
//             bson_error_t err;
//             if (!mongoc_collection_delete_many(
//                 coll_, query, nullptr, nullptr, &err))
//             {
//                 throw MongoException(err.message);
//             }
//         }
//
//         // ---------------- UPDATE / UPSERT ----------------
//
//         void update(const bson_t* query,
//             const bson_t* update,
//             bool upsert = false)
//         {
//             bson_error_t err;
//             bson_t opts;
//             bson_init(&opts);
//             BSON_APPEND_BOOL(&opts, "upsert", upsert);
//
//             if (!mongoc_collection_update_many(
//                 coll_, query, update, &opts, nullptr, &err))
//             {
//                 bson_destroy(&opts);
//                 throw MongoException(err.message);
//             }
//
//             bson_destroy(&opts);
//         }
//
//         // ---------------- INDEX ----------------
//
//         void createIndex(const bson_t* keys, bool unique = false)
//         {
//             bson_error_t err;
//             bson_t opts;
//             bson_init(&opts);
//             BSON_APPEND_BOOL(&opts, "unique", unique);
//
//             if (!mongoc_collection_create_index_with_opts(
//                 coll_, keys, &opts, nullptr, &err))
//             {
//                 bson_destroy(&opts);
//                 throw MongoException(err.message);
//             }
//
//             bson_destroy(&opts);
//         }
//
//         MongoCollection(const MongoCollection&) = delete;
//         MongoCollection& operator=(const MongoCollection&) = delete;
//
//     private:
//         mongoc_collection_t* coll_ = nullptr;
//     };
//
// } // namespace mongo
