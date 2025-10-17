"""
ASGI config for KBESettings project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.2/howto/deployment/asgi/
"""

import os

from channels.auth import AuthMiddlewareStack
from channels.routing import ProtocolTypeRouter, URLRouter
from django.core.asgi import get_asgi_application

from cluster import routing

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'KBESettings.settings')

# application = get_asgi_application()



application = ProtocolTypeRouter({
    "http": get_asgi_application(),  # 继续支持 HTTP
    "websocket": AuthMiddlewareStack(
        URLRouter(
            routing.websocket_urlpatterns  # 👈 引入 websocket 路由
        )
    ),
})