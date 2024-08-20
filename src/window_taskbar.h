#ifndef WINDOW_TASKBAR_H
#define WINDOW_TASKBAR_H

#include <godot_cpp/classes/window.hpp>

namespace godot {

class WindowTaskbar : public Window {
    GDCLASS(WindowTaskbar, Window)

    private:
      bool taskbar_visible;

    protected:
		  static void _bind_methods();

    public:
      WindowTaskbar();
      ~WindowTaskbar();

      void _process(double delta) override;
      virtual void _ready() override;
      void set_taskbar_visible(const bool visible);
      bool get_taskbar_visible() const;

    };

}

#endif