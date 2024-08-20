extends WindowTaskbar


@onready var _MainWindow: Window = get_window()


func _on_check_button_pressed() -> void:
	# var handle = DisplayServer.window_get_native_handle(DisplayServer.HandleType.WINDOW_HANDLE, _MainWindow.get_window_id())
	# var taskbar_utils = TaskbarUtils.new()
	# taskbar_utils.hide_taskbar(handle)
	taskbar_visible = !taskbar_visible
