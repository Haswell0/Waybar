#pragma once

#include <fmt/format.h>
#include <fstream>
#include <jack/jack.h>
#include <proc/readproc.h>
#include "ALabel.hpp"
#include "util/sleeper_thread.hpp"

namespace waybar::modules {

class JACK : public ALabel {
 public:
  JACK(const std::string&, const Json::Value&);
  ~JACK() = default;
  auto update() -> void;
  jack_nframes_t      bufsize_;
  jack_client_t*      client_;
  unsigned int        xruns_;
  std::string         state_;

 private:
  std::string         JACKState();

  jack_nframes_t      samplerate_;
  util::SleeperThread thread_;
};

}  // namespace waybar::modules
