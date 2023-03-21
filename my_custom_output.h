#include "esphome.h"
using namespace esphome;

// HighFrequencyLoop increases the loop speed.
class HighFrequencyLoop : public Component, public BinaryOutput {
  private:
    HighFrequencyLoopRequester high_freq_;
  public:
    void write_state(bool state) override {
      if(state)
        this->high_freq_.start();
      else
        this->high_freq_.stop();
      ESP_LOGI("custom_binary", "High frequency = %d", this->high_freq_.is_high_frequency());
    }
};
