#pragma once

#include "Event.h"
#include "FileSystemAdapter.h"

#include <chrono>

namespace inotify {

class Notification {
  public:
    Notification(
        const Event& event,
        const inotifypp::filesystem::path& path,
        std::chrono::steady_clock::time_point time);

  public:
    const Event event;
    const inotifypp::filesystem::path path;
    const std::chrono::steady_clock::time_point time;
};
}
