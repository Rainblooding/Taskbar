#ifndef TASKBAR_UTILS_H
#define TASKBAR_UTILS_H

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/classes/window.hpp>

namespace godot {

class TaskbarUtils : public Object {
	GDCLASS(TaskbarUtils, Object)
	

	protected:
		static void _bind_methods();

	public:
	
		~TaskbarUtils();

		void hide_taskbar(int64_t window_id);
		void show_taskbar(int64_t window_id);
	};

}

#endif
