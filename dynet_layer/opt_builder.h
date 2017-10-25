#ifndef __TWPIPE_OPTIMIZER_BUILDER_H__
#define __TWPIPE_OPTIMIZER_BUILDER_H__

#include <boost/program_options.hpp>
#include "dynet/model.h"
#include "dynet/training.h"

namespace po = boost::program_options;

struct OptimizerBuilder {
  enum OptimizerType {
    kSimpleSGD,
    kMomentumSGD,
    kAdaGrad,
    kAdaDelta,
    kRMSProp,
    kAdam
  };

  OptimizerType optimizer_type;
  float eta0;
  float adam_beta1;
  float adam_beta2;
  bool enable_clipping;

  static po::options_description get_options();
  static std::string get_optimizer_signature(const po::variables_map & conf);

  OptimizerBuilder(const po::variables_map& conf);

  dynet::Trainer * build(dynet::ParameterCollection & model);

  void update(dynet::Trainer * trainer, unsigned iter);
};

#endif  //  end for TRAIN_H