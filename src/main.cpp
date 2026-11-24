// main.cpp — entry point. Wires config and subsystems together.

#include "robrunperformance/settings.h"
#include "robrunperformance/tuner.h"
#include "robrunperformance/network.h"
#include "robrunperformance/profiles.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    robrunperformance::Settings settings = robrunperformance::Settings::load_default();
    robrunperformance::Tuner tuner(settings.store_path);
    robrunperformance::Network network(settings.store_path);
    robrunperformance::Profiles profiles(settings.store_path);
    std::fprintf(stderr, "[rob-run-performance] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
