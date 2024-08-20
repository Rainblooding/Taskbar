#include "taskbar_utils.h"
#include <godot_cpp/core/class_db.hpp>
#include <windows.h>

using namespace godot;

void TaskbarUtils::_bind_methods() {
	ClassDB::bind_method(D_METHOD("hide_taskbar", "window_id"), &TaskbarUtils::hide_taskbar);
	ClassDB::bind_method(D_METHOD("show_taskbar", "window_id"), &TaskbarUtils::show_taskbar);
}

TaskbarUtils::~TaskbarUtils() {
	// Add your cleanup here.
}

void TaskbarUtils::hide_taskbar(int64_t handle) {
	// Hide the taskbar by modifying the window style
	HWND hwnd = reinterpret_cast<HWND>(handle);
	if (hwnd) {
		LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
		SetWindowLong(hwnd, GWL_EXSTYLE, (style & ~WS_EX_APPWINDOW) | WS_EX_TOOLWINDOW);
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}
}

void TaskbarUtils::show_taskbar(int64_t handle) {
	// Hide the taskbar by modifying the window style
	HWND hwnd = reinterpret_cast<HWND>(handle);
	if (hwnd) {
	  	LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
		// 移除 WS_EX_TOOLWINDOW 样式，并添加 WS_EX_APPWINDOW 样式
		style = (style & ~WS_EX_TOOLWINDOW) | WS_EX_APPWINDOW;
		// 设置新的扩展样式
		SetWindowLong(hwnd, GWL_EXSTYLE, style);
		// 应用更改
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}
}