

<div align="center">
<img alt="SwanLab" src="https://github.com/KBEngineLab/KBEngineNexMaterials/blob/main/images/kbenexlogo.png?raw=true" width="80" height="80" style="margin-top:20px;">


<h1>KBEngine Nex</h1>

一款开源的游戏服务端引擎，客户端通过简单的约定协议就能与服务端通讯

使用KBEngine插件能够快速与(Unity3D, UE, Cocos等等)技术结合形成一个完整的客户端


<a href="https://www.kbelab.com/">🎨 官网</a> · <a href="https://api.kbelab.com/">🍀 文档</a> · <a href="https://github.com/KBEngineLab/KBEngine-Nex/issues">报告问题</a> · <a href="https://github.com/KBEngineLab/KBEngine-Nex/discussions/categories/ideas">建议反馈</a> · <a href="UPDATE.md">更新日志</a> · <a href="https://github.com/kbengine/kbengine">KBEngine</a>


[![][qq1-shield]][qq1-link]

[![][build-status-shield]][build-status-link] [![][release-shield]][release-link] [![][dockerhub-shield]][dockerhub-link] [![][last-commit-shield]][last-commit-shield-link] [![][github-issues-shield]][github-issues-shield-link] [![][github-stars-shield]][github-stars-link] [![JetBrains Plugins](https://img.shields.io/jetbrains/plugin/v/27963-kbenginex.svg)](https://plugins.jetbrains.com/plugin/27963-kbenginex)

</div>


## Pycharm 插件

**Pycharm插件已发布，支持 2024.2 - 2025.\***

[![JetBrains Plugins](https://img.shields.io/jetbrains/plugin/v/27963-kbenginex.svg)](https://plugins.jetbrains.com/plugin/27963-kbenginex)

[点击查看插件使用文档](https://www.kbelab.com/kbex/)


## 什么是 KBEngine

https://github.com/kbengine/kbengine

一款开源的游戏服务端引擎，客户端通过简单的约定协议就能与服务端通讯， 使用KBEngine插件能够快速与(Unity3D, UE, Cocos等等)技术结合形成一个完整的客户端。 

服务端底层框架使用C++编写，游戏逻辑层使用Python(支持热更新)，开发者无需重复的实现一些游戏服务端通用的底层技术， 将精力真正集中到游戏开发层面上来，快速的打造各种网络游戏。




## 什么是 KBEngine Nex

KBEngine Nex 是在KBEngine 2.5.12 的基础上社区继续维护的版本
- Pycharm IDE 插件支持
- UE5 SDK支持
- Cocos SDK支持
- Python 版本升级（ 3.7 -> 3.13 ）
- 支持 MacOS 开发环境

## 特性

- **多人同时在线**：支持持大量的玩家同时在线实时游戏的交互。 具体承载量需要根据游戏的类型和复杂度以及硬件的性能来决定。
- **自动备份**：支持定时自动备份数据到数据库，同时也提供了API让用户主动调用一次写库功能。
- **跨平台**：Linux支持(x86/x64): Ubuntu, Debain, Centos, Redhat。 支持所有版本的Windows系统，但目前仅用于调试和游戏开发环境。
- **完善的客户端SDK**：客户端开发者所要做的就是接收事件数据，然后渲染。 SDK支持UE、Unity、Cocos等等。
- **配置简单**：只需要修改kbengine.xml 与 kbengine_defaults.xml 配置文件。
- **动态负载平衡**：为了更有效地利用有限的硬件，动态负载均衡技术在高负载时引擎仍然能够很好的工作。
- **强大的配套工具**：在线调试、查看服务端状态、启动与关闭。 在线升级、策划数据导出、等等。
- **快速开发游戏**：只需要使用Python就可以快速的进行设计游戏。 底层安全可靠，保证效率。


## 支持的引擎

<span height="20">&nbsp;</span>
<div align="center">
	<a href="https://unity.com/" target="_blank"><img src="https://raw.githubusercontent.com/KBEngineLab/KBEngineNexMaterials/938f6a964c299176995384985cde18fb88accb5c/images/third_party_logo/unity.svg" alt="Unity" height="30"></a>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="https://www.unrealengine.com/zh-CN" target="_blank"><img src="https://raw.githubusercontent.com/KBEngineLab/KBEngineNexMaterials/938f6a964c299176995384985cde18fb88accb5c/images/third_party_logo/unreal-engine.svg" alt="UE5" height="30"></a>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="https://www.cocos.com/" target="_blank"><img src="https://github.com/KBEngineLab/KBEngineNexMaterials/blob/main/images/third_party_logo/cocos_dark.png?raw=true" alt="Cocos" height="30"></a>
</div>

<span height="20">&nbsp;</span>

<div align="center">
	<a href="https://layaair.com" target="_blank"><img src="https://github.com/KBEngineLab/KBEngineNexMaterials/blob/main/images/third_party_logo/layaair-logo_dark.png?raw=true" alt="LayaAir" height="30"></a>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="https://godotengine.org/" target="_blank"><img src="https://raw.githubusercontent.com/KBEngineLab/KBEngineNexMaterials/938f6a964c299176995384985cde18fb88accb5c/images/third_party_logo/godot-logo.svg" alt="Godot" height="30"></a>
</div>


## Demo

	Unity		: https://github.com/KBEngineLab/demo_kbengine_unity3d_default
	UE5		: https://github.com/KBEngineLab/demo_kbengine_ue5_default
	CocosCreator	: https://github.com/KBEngineLab/demo_kbengine_cocos_creator_default
	Godot		: https://github.com/KBEngineLab/demo_kbengine_godot_default
	UE4		: https://github.com/kbengine/kbengine_ue4_demo
	
<!-- Cocos2d_js	: https://github.com/kbengine/kbengine_cocos2d_js_demo -->
<!-- Godot Engine	: https://github.com/krogank9/kbe_godot_demo -->





[build-status-shield]: https://ci.appveyor.com/api/projects/status/aij7ox4twu53v3v0/branch/master?svg=true
[build-status-link]: https://ci.appveyor.com/project/KBEngineLab/kbengine-nex/branch/master

[release-shield]: https://img.shields.io/github/v/release/KBEngineLab/KBEngine-Nex?color=3eaf7c&labelColor=black&logo=github&style=flat-square
[release-link]: https://github.com/KBEngineLab/KBEngine-Nex/releases


[last-commit-shield]: https://img.shields.io/github/last-commit/KBEngineLab/KBEngine-Nex?color=c4f042&labelColor=black&style=flat-square
[last-commit-shield-link]: https://github.com/KBEngineLab/KBEngine-Nex/commits/master/


[dockerhub-shield]: https://img.shields.io/docker/v/kbenginelab/kbengine-nex?color=369eff&label=docker&labelColor=black&logoColor=white&style=flat-square
[dockerhub-link]: https://hub.docker.com/r/kbenginelab/kbengine-nex/tags


[github-stars-shield]: https://img.shields.io/github/stars/KBEngineLab/KBEngine-Nex?labelColor&style=flat-square&color=ffcb47
[github-stars-link]: https://github.com/KBEngineLab/KBEngine-Nex


[github-issues-shield]: https://img.shields.io/github/issues/KBEngineLab/KBEngine-Nex?labelColor=black&style=flat-square&color=ff80eb
[github-issues-shield-link]: https://github.com/KBEngineLab/KBEngine-Nex/issues


[qq1-shield]: https://img.shields.io/badge/QQ交流①群-150506969-3eaf7c
[qq1-link]: https://qm.qq.com/q/IuzGOBQqK4


