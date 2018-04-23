#include "canvas/Persistency/Common/Wrapper.h"
#include <vector>
#include "sbndcode/DaqAnalysis/ChannelData.hh"
#include "sbndcode/DaqAnalysis/HeaderData.hh"

namespace {
  struct dictionary {
    daqAnalysis::ChannelData c;
    std::vector<daqAnalysis::ChannelData> c_v;
    art::Wrapper<daqAnalysis::ChannelData> c_w;
    art::Wrapper<std::vector<daqAnalysis::ChannelData>> c_v_w;

    daqAnalysis::ReducedChannelData rc;
    std::vector<daqAnalysis::ReducedChannelData> rc_v;
    art::Wrapper<daqAnalysis::ReducedChannelData> rc_w;
    art::Wrapper<std::vector<daqAnalysis::ReducedChannelData>> rc_v_w;

    daqAnalysis::HeaderData h;
    std::vector<daqAnalysis::HeaderData> h_v;
    art::Wrapper<daqAnalysis::HeaderData> h_w;
    art::Wrapper<std::vector<daqAnalysis::HeaderData>> h_v_w;

    std::vector<std::vector<short>> vs_v;
    art::Wrapper<std::vector<std::vector<short>>> vs_v_w;
    
  };
}


