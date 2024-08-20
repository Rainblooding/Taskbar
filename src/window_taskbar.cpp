#include "window_taskbar.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/display_server.hpp>
#include <windows.h>

using namespace godot;

void WindowTaskbar::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_taskbar_visible"), &WindowTaskbar::get_taskbar_visible);
	ClassDB::bind_method(D_METHOD("set_taskbar_visible", "visible"), &WindowTaskbar::set_taskbar_visible);
	ClassDB::add_property("WindowTaskbar", PropertyInfo(Variant::BOOL, "taskbar_visible"), "set_taskbar_visible", "get_taskbar_visible");

}

WindowTaskbar::WindowTaskbar() {
    taskbar_visible = true;
}

WindowTaskbar::~WindowTaskbar() {
	// Add your cleanup here.
}

void WindowTaskbar::_ready() {
}
void WindowTaskbar::_process(double delta) {

}

void WindowTaskbar::set_taskbar_visible(const bool visible) {
    int32_t window_id = get_window_id();
    int64_t native_handle = DisplayServer::get_singleton()->window_get_native_handle(DisplayServer::WINDOW_HANDLE, window_id);
    HWND hwnd = reinterpret_cast<HWND>(native_handle);
    if(visible && hwnd) {
        LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
        // 移除 WS_EX_TOOLWINDOW 样式，并添加 WS_EX_APPWINDOW 样式
        style = (style & ~WS_EX_TOOLWINDOW) | WS_EX_APPWINDOW;
        // 设置新的扩展样式
        SetWindowLong(hwnd, GWL_EXSTYLE, style);
        // 应用更改
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    } else if(hwnd) {
        LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
        // 通过按位与运算符移除 WS_EX_APPWINDOW 样式
        // 将窗口设置为工具窗口
        SetWindowLong(hwnd, GWL_EXSTYLE, (style & ~WS_EX_APPWINDOW) | WS_EX_TOOLWINDOW);
        // 应用更改
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    }
	taskbar_visible = visible;
}

bool WindowTaskbar::get_taskbar_visible() const {
	return taskbar_visible;
}
