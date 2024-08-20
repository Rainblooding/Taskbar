# Taskbar
可以使godot的window窗口在任务栏中隐藏起来的一个插件

# 前置
暂时支持`windows`平台
需要先看`godot`官网的`c++教程`

[GDExtension C++ 示例](https://docs.godotengine.org/zh-cn/4.x/tutorials/scripting/gdextension/gdextension_cpp_example.html)

然后在目录中使用`scons platform=windows`编译, 编译后在`GodotProject/bin`下会出来一个`dll`

然后使用`godot`打开项目`GodotProject`

```gdscript
func _on_check_button_pressed() -> void:
	# var handle = DisplayServer.window_get_native_handle(DisplayServer.HandleType.WINDOW_HANDLE, _MainWindow.get_window_id())
	# var taskbar_utils = TaskbarUtils.new()
	# taskbar_utils.hide_taskbar(handle)
	taskbar_visible = !taskbar_visible

```

# 说明
本人不会`c++`代码来源于`chargpt`, 所以质量堪忧

# bug
隐藏任务栏后, 窗口的标题栏样式会变, 不知道有什么更好的办法可以隐藏任务栏
隐藏后不会进入到托盘, 这个在godot4.3中已经提供了托盘功能