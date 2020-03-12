#pragma once

#include <torch/arg.h>
#include <torch/csrc/WindowsTorchApiMacro.h>
#include <torch/types.h>

namespace torch {
namespace nn {

/// Options for the `ELU` module.
///
/// Example:
/// ```
/// ELU model(ELUOptions().alpha(42.42).inplace(true));
/// ```
struct TORCH_API ELUOptions {
  /// The `alpha` value for the ELU formulation. Default: 1.0
  TORCH_ARG(double, alpha) = 1.0;

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

namespace functional {
/// Options for `torch::nn::functional::elu`.
///
/// Example:
/// ```
/// namespace F = torch::nn::functional;
/// F::elu(x, F::ELUFuncOptions().alpha(0.42).inplace(true));
/// ```
using ELUFuncOptions = ELUOptions;
} // namespace functional

// ============================================================================

/// Options for the `SELU` module.
///
/// Example:
/// ```
/// SELU model(SELUOptions().inplace(true));
/// ```
struct TORCH_API SELUOptions {
  /* implicit */ SELUOptions(bool inplace = false);

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace);
};

namespace functional {
/// Options for `torch::nn::functional::selu`.
///
/// Example:
/// ```
/// namespace F = torch::nn::functional;
/// F::selu(input, F::SELUFuncOptions(false));
/// ```
using SELUFuncOptions = SELUOptions;
} // namespace functional

// ============================================================================

/// Options for the `GLU` module.
///
/// Example:
/// ```
/// GLU model(GLUOptions(1));
/// ```
struct TORCH_API GLUOptions {
  /* implicit */ GLUOptions(int64_t dim = -1);

  /// the dimension on which to split the input. Default: -1
  TORCH_ARG(int64_t, dim);
};

namespace functional {
using GLUFuncOptions = GLUOptions;
} // namespace functional

// ============================================================================

/// Options for the `Hardshrink` module.
///
/// Example:
/// ```
/// Hardshrink model(HardshrinkOptions().lambda(42.42));
/// ```
struct TORCH_API HardshrinkOptions {
  /* implicit */ HardshrinkOptions(double lambda = 0.5);

  /// the `lambda` value for the Hardshrink formulation. Default: 0.5
  TORCH_ARG(double, lambda);
};

namespace functional {
using HardshrinkFuncOptions = HardshrinkOptions;
} // namespace functional

// ============================================================================

/// Options for the `Hardtanh` module.
///
/// Example:
/// ```
/// Hardtanh model(HardtanhOptions().min_val(-42.42).max_val(0.42).inplace(true));
/// ```
struct TORCH_API HardtanhOptions {
  /// minimum value of the linear region range. Default: -1
  TORCH_ARG(double, min_val) = -1.0;

  /// maximum value of the linear region range. Default: 1
  TORCH_ARG(double, max_val) = 1.0;

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

namespace functional {
using HardtanhFuncOptions = HardtanhOptions;
} // namespace functional

// ============================================================================

/// Options for the `LeakyReLU` module.
///
/// Example:
/// ```
/// LeakyReLU model(LeakyReLUOptions().negative_slope(0.42).inplace(true));
/// ```
struct TORCH_API LeakyReLUOptions {
  /// Controls the angle of the negative slope. Default: 1e-2
  TORCH_ARG(double, negative_slope) = 1e-2;

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

namespace functional {
/// yf225TODO
///
/// Options for `torch::nn::functional::leaky_relu`.
///
/// Example:
/// ```
/// namespace F = torch::nn::functional;
/// F::leaky_relu(x, F::LeakyReLUFuncOptions().negative_slope(0.42).inplace(true));
/// ```
using LeakyReLUFuncOptions = LeakyReLUOptions;
}

// ============================================================================

/// Options for the Softmax module.
///
/// Example:
/// ```
/// Softmax model(SoftmaxOptions(1));
/// ```
struct TORCH_API SoftmaxOptions {
  SoftmaxOptions(int64_t dim);

  /// Dimension along which Softmax will be computed.
  TORCH_ARG(int64_t, dim);
};

// ============================================================================

namespace functional {

struct TORCH_API SoftmaxFuncOptions {
  SoftmaxFuncOptions(int64_t dim);

  /// Dimension along which Softmax will be computed.
  TORCH_ARG(int64_t, dim);

  /// the desired data type of returned tensor.
  /// If specified, the input tensor is casted to `dtype` before the operation
  /// is performed. This is useful for preventing data type overflows. Default: None.
  TORCH_ARG(c10::optional<torch::Dtype>, dtype) = c10::nullopt;
};

} // namespace functional

// ============================================================================

/// Options for the Softmin module.
///
/// Example:
/// ```
/// Softmin model(SoftminOptions(1));
/// ```
struct TORCH_API SoftminOptions {
  SoftminOptions(int64_t dim);

  /// Dimension along which Softmin will be computed.
  TORCH_ARG(int64_t, dim);
};

// ============================================================================

namespace functional {

struct TORCH_API SoftminFuncOptions {
  SoftminFuncOptions(int64_t dim);

  /// Dimension along which Softmin will be computed.
  TORCH_ARG(int64_t, dim);

  /// the desired data type of returned tensor.
  /// If specified, the input tensor is casted to `dtype` before the operation
  /// is performed. This is useful for preventing data type overflows. Default: None.
  TORCH_ARG(c10::optional<torch::Dtype>, dtype) = c10::nullopt;
};

} // namespace functional

// ============================================================================

/// Options for the LogSoftmax module.
///
/// Example:
/// ```
/// LogSoftmax model(LogSoftmaxOptions(1));
/// ```
struct TORCH_API LogSoftmaxOptions {
  LogSoftmaxOptions(int64_t dim);

  /// Dimension along which LogSoftmax will be computed.
  TORCH_ARG(int64_t, dim);
};

// ============================================================================

namespace functional {

struct TORCH_API LogSoftmaxFuncOptions {
  LogSoftmaxFuncOptions(int64_t dim);

  /// Dimension along which LogSoftmax will be computed.
  TORCH_ARG(int64_t, dim);

  /// the desired data type of returned tensor.
  /// If specified, the input tensor is casted to `dtype` before the operation
  /// is performed. This is useful for preventing data type overflows. Default: None.
  TORCH_ARG(c10::optional<torch::Dtype>, dtype) = c10::nullopt;
};

} // namespace functional

// ============================================================================

/// Options for the `PReLU` module.
///
/// Example:
/// ```
/// PReLU model(PReLUOptions().num_parameters(42));
/// ```
struct TORCH_API PReLUOptions {
  /// number of `a` to learn. Although it takes an int as input, there is only
  /// two values are legitimate: 1, or the number of channels at input. Default: 1
  TORCH_ARG(int64_t, num_parameters) = 1;

  /// the initial value of `a`. Default: 0.25
  TORCH_ARG(double, init) = 0.25;
};

namespace functional {
using PReLUFuncOptions = PReLUOptions;
} // namespace functional

// ============================================================================

/// Options for the `ReLU` module.
///
/// Example:
/// ```
/// ReLU model(ReLUOptions().inplace(true));
/// ```
struct TORCH_API ReLUOptions {
  /* implicit */ ReLUOptions(bool inplace = false);

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace);
};

namespace functional {
using ReLUFuncOptions = ReLUOptions;
} // namespace functional

// ============================================================================

/// Options for the `ReLU6` module.
///
/// Example:
/// ```
/// ReLU6 model(ReLU6Options().inplace(true));
/// ```
struct TORCH_API ReLU6Options {
  /* implicit */ ReLU6Options(bool inplace = false);

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace);
};

namespace functional {
using ReLU6FuncOptions = ReLU6Options;
} // namespace functional

// ============================================================================

/// Options for the `RReLU` module.
///
/// Example:
/// ```
/// RReLU model(RReLUOptions().lower(0.24).upper(0.42).inplace(true));
/// ```
struct TORCH_API RReLUOptions {
  /// lower bound of the uniform distribution. Default: 1/8
  TORCH_ARG(double, lower) = 1.0 / 8.0;

  /// upper bound of the uniform distribution. Default: 1/3
  TORCH_ARG(double, upper) = 1.0 / 3.0;

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

// ============================================================================

namespace functional {

struct TORCH_API RReLUFuncOptions {
  /// lower bound of the uniform distribution. Default: 1/8
  TORCH_ARG(double, lower) = 1.0 / 8.0;

  /// upper bound of the uniform distribution. Default: 1/3
  TORCH_ARG(double, upper) = 1.0 / 3.0;

  TORCH_ARG(bool, training) = false;

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

} // namespace functional

// ============================================================================

/// Options for the `CELU` module.
///
/// Example:
/// ```
/// CELU model(CELUOptions().alpha(42.42).inplace(true));
/// ```
struct TORCH_API CELUOptions {
  /// The `alpha` value for the CELU formulation. Default: 1.0
  TORCH_ARG(double, alpha) = 1.0;

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

namespace functional {
using CELUFuncOptions = CELUOptions;
} // namespace functional

// ============================================================================

/// Options for the `Softplus` module.
///
/// Example:
/// ```
/// Softplus model(SoftplusOptions().beta(0.24).threshold(42.42));
/// ```
struct TORCH_API SoftplusOptions {
  /// the `beta` value for the Softplus formulation. Default: 1
  TORCH_ARG(double, beta) = 1.0;

  /// values above this revert to a linear function. Default: 20
  TORCH_ARG(double, threshold) = 20.0;
};

namespace functional {
using SoftplusFuncOptions = SoftplusOptions;
} // namespace functional

// ============================================================================

/// Options for the `Softshrink` module.
///
/// Example:
/// ```
/// Softshrink model(SoftshrinkOptions(42.42));
/// ```
struct TORCH_API SoftshrinkOptions {
  /* implicit */ SoftshrinkOptions(double lambda = 0.5);

  /// the `lambda` value for the Softshrink formulation. Default: 0.5
  TORCH_ARG(double, lambda);
};

namespace functional {
using SoftshrinkFuncOptions = SoftshrinkOptions;
} // namespace functional

// ============================================================================

/// Options for the `Threshold` module.
///
/// Example:
/// ```
/// Threshold model(ThresholdOptions(42.42, 24.24).inplace(true));
/// ```
struct TORCH_API ThresholdOptions {
  ThresholdOptions(double threshold, double value)
   : threshold_(threshold), value_(value) {}

  /// The value to threshold at
  TORCH_ARG(double, threshold);

  /// The value to replace with
  TORCH_ARG(double, value);

  /// can optionally do the operation in-place. Default: False
  TORCH_ARG(bool, inplace) = false;
};

namespace functional {
using ThresholdFuncOptions = ThresholdOptions;
} // namespace functional

// ============================================================================

namespace functional {

/// Options for Gumbel Softmax functional.
struct TORCH_API GumbelSoftmaxFuncOptions {
  /// non-negative scalar temperature
  TORCH_ARG(double, tau) = 1.0;

  /// returned samples will be discretized as one-hot vectors,
  /// but will be differentiated as if it is the soft sample in autograd. Default: False
  TORCH_ARG(bool, hard) = false;

  /// dimension along which softmax will be computed. Default: -1
  TORCH_ARG(int, dim) = -1;
};

} // namespace functional

// ============================================================================

/// Options for the `MultiheadAttention` module.
///
/// Example:
/// ```
/// MultiheadAttention model(MultiheadAttentionOptions(20, 10).bias(false));
/// ```
struct TORCH_API MultiheadAttentionOptions {
  MultiheadAttentionOptions(int64_t embed_dim, int64_t num_heads);

  /// total dimension of the model.
  TORCH_ARG(int64_t, embed_dim);

  /// parallel attention heads.
  TORCH_ARG(int64_t, num_heads);

  /// a Dropout layer on attn_output_weights. Default: 0.0.
  TORCH_ARG(double, dropout) = 0.0;

  /// add bias as module parameter. Default: true.
  TORCH_ARG(bool, bias) = true;

  /// add bias to the key and value sequences at dim=0.
  TORCH_ARG(bool, add_bias_kv) = false;

  /// add a new batch of zeros to the key and value sequences at dim=1.
  TORCH_ARG(bool, add_zero_attn) = false;

  /// total number of features in key. Default: c10::nullopt.
  TORCH_ARG(int64_t, kdim);

  /// total number of features in key. Default: c10::nullopt.
  TORCH_ARG(int64_t, vdim);
};

// ============================================================================

namespace functional {

/// Options for `torch::nn::functional::multi_head_attention_forward`
struct TORCH_API MultiheadAttentionForwardFuncOptions {

  MultiheadAttentionForwardFuncOptions(
    int64_t embed_dim_to_check, int64_t num_heads,
    Tensor in_proj_weight, Tensor in_proj_bias,
    Tensor bias_k, Tensor bias_v,
    bool add_zero_attn, double dropout_p,
    Tensor out_proj_weight, Tensor out_proj_bias
  );

  TORCH_ARG(int64_t, embed_dim_to_check);

  TORCH_ARG(int64_t, num_heads);

  TORCH_ARG(Tensor, in_proj_weight);

  TORCH_ARG(Tensor, in_proj_bias);

  TORCH_ARG(Tensor, bias_k);

  TORCH_ARG(Tensor, bias_v);

  TORCH_ARG(bool, add_zero_attn);

  TORCH_ARG(double, dropout_p);

  TORCH_ARG(Tensor, out_proj_weight);

  TORCH_ARG(Tensor, out_proj_bias);

  TORCH_ARG(bool, training) = true;

  TORCH_ARG(Tensor, key_padding_mask) = {};

  TORCH_ARG(bool, need_weights) = true;

  TORCH_ARG(Tensor, attn_mask) = {};

  TORCH_ARG(bool, use_separate_proj_weight) = false;

  TORCH_ARG(Tensor, q_proj_weight) = {};

  TORCH_ARG(Tensor, k_proj_weight) = {};

  TORCH_ARG(Tensor, v_proj_weight) = {};

  TORCH_ARG(Tensor, static_k) = {};

  TORCH_ARG(Tensor, static_v) = {};
};

} // namespace functional

} // namespace nn
} // namespace torch
