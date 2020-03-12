#pragma once

#include <torch/arg.h>
#include <torch/csrc/WindowsTorchApiMacro.h>
#include <torch/expanding_array.h>
#include <torch/types.h>

namespace torch {
namespace nn {

/// Options for a `D`-dimensional avgpool module.
template <size_t D>
struct AvgPoolOptions {
  AvgPoolOptions(ExpandingArray<D> kernel_size)
      : kernel_size_(kernel_size), stride_(kernel_size) {}

  /// the size of the window to take an average over
  TORCH_ARG(ExpandingArray<D>, kernel_size);

  /// the stride of the window. Default value is `kernel_size`
  TORCH_ARG(ExpandingArray<D>, stride);

  /// implicit zero padding to be added on both sides
  TORCH_ARG(ExpandingArray<D>, padding) = 0;

  /// when True, will use `ceil` instead of `floor` to compute the output shape
  TORCH_ARG(bool, ceil_mode) = false;

  /// when True, will include the zero-padding in the averaging calculation
  TORCH_ARG(bool, count_include_pad) = true;

  /// if specified, it will be used as divisor, otherwise `kernel_size` will be used
  TORCH_ARG(c10::optional<int64_t>, divisor_override) = c10::nullopt;
};

/// Options for the `AvgPool1d` module.
///
/// Example:
/// ```
/// AvgPool1d model(AvgPool1dOptions(3).stride(2));
/// ```
using AvgPool1dOptions = AvgPoolOptions<1>;

/// Options for the `AvgPool2d` module.
///
/// Example:
/// ```
/// AvgPool2d model(AvgPool2dOptions({3, 2}).stride({2, 2}));
/// ```
using AvgPool2dOptions = AvgPoolOptions<2>;

/// Options for the `AvgPool3d` module.
///
/// Example:
/// ```
/// AvgPool3d model(AvgPool3dOptions(5).stride(2));
/// ```
using AvgPool3dOptions = AvgPoolOptions<3>;

namespace functional {
using AvgPool1dFuncOptions = AvgPool1dOptions;
} // namespace functional
namespace functional {
using AvgPool2dFuncOptions = AvgPool2dOptions;
} // namespace functional
namespace functional {
using AvgPool3dFuncOptions = AvgPool3dOptions;
} // namespace functional

// ============================================================================

/// Options for a `D`-dimensional maxpool module.
template <size_t D>
struct MaxPoolOptions {
  MaxPoolOptions(ExpandingArray<D> kernel_size)
      : kernel_size_(kernel_size), stride_(kernel_size) {}

  /// the size of the window to take a max over
  TORCH_ARG(ExpandingArray<D>, kernel_size);

  /// the stride of the window. Default value is `kernel_size
  TORCH_ARG(ExpandingArray<D>, stride);

  /// implicit zero padding to be added on both sides
  TORCH_ARG(ExpandingArray<D>, padding) = 0;

  /// a parameter that controls the stride of elements in the window
  TORCH_ARG(ExpandingArray<D>, dilation) = 1;

  /// when True, will use `ceil` instead of `floor` to compute the output shape
  TORCH_ARG(bool, ceil_mode) = false;
};

/// Options for the `MaxPool1d` module.
///
/// Example:
/// ```
/// MaxPool1d model(MaxPool1dOptions(3).stride(2));
/// ```
using MaxPool1dOptions = MaxPoolOptions<1>;

/// Options for the `MaxPool2d` module.
///
/// Example:
/// ```
/// MaxPool2d model(MaxPool2dOptions({3, 2}).stride({2, 2}));
/// ```
using MaxPool2dOptions = MaxPoolOptions<2>;

/// Options for the `MaxPool3d` module.
///
/// Example:
/// ```
/// MaxPool3d model(MaxPool3dOptions(3).stride(2));
/// ```
using MaxPool3dOptions = MaxPoolOptions<3>;

namespace functional {
using MaxPool1dFuncOptions = MaxPool1dOptions;
} // namespace functional
namespace functional {
using MaxPool2dFuncOptions = MaxPool2dOptions;
} // namespace functional
namespace functional {
using MaxPool3dFuncOptions = MaxPool3dOptions;
} // namespace functional

// ============================================================================

/// Options for a `D`-dimensional adaptive maxpool module.
template <size_t D>
struct AdaptiveMaxPoolOptions {
  AdaptiveMaxPoolOptions(ExpandingArray<D> output_size)
      : output_size_(output_size) {}

  /// the target output size
  TORCH_ARG(ExpandingArray<D>, output_size);
};

/// Options for the `AdaptiveMaxPool1d` module.
///
/// Example:
/// ```
/// AdaptiveMaxPool1d model(AdaptiveMaxPool1dOptions(3));
/// ```
using AdaptiveMaxPool1dOptions = AdaptiveMaxPoolOptions<1>;

/// Options for the `AdaptiveMaxPool2d` module.
///
/// Example:
/// ```
/// AdaptiveMaxPool2d model(AdaptiveMaxPool2dOptions({3, 2}));
/// ```
using AdaptiveMaxPool2dOptions = AdaptiveMaxPoolOptions<2>;

/// Options for the `AdaptiveMaxPool3d` module.
///
/// Example:
/// ```
/// AdaptiveMaxPool3d model(AdaptiveMaxPool3dOptions(3));
/// ```
using AdaptiveMaxPool3dOptions = AdaptiveMaxPoolOptions<3>;

namespace functional {
using AdaptiveMaxPool1dFuncOptions = AdaptiveMaxPool1dOptions;
} // namespace functional
namespace functional {
using AdaptiveMaxPool2dFuncOptions = AdaptiveMaxPool2dOptions;
} // namespace functional
namespace functional {
using AdaptiveMaxPool3dFuncOptions = AdaptiveMaxPool3dOptions;
} // namespace functional

// ============================================================================

/// Options for a `D`-dimensional adaptive avgpool module.
template <size_t D>
struct AdaptiveAvgPoolOptions {
  AdaptiveAvgPoolOptions(ExpandingArray<D> output_size)
      : output_size_(output_size) {}

  /// the target output size
  TORCH_ARG(ExpandingArray<D>, output_size);
};

/// Options for the `AdaptiveAvgPool1d` module.
///
/// Example:
/// ```
/// AdaptiveAvgPool1d model(AdaptiveAvgPool1dOptions(5));
/// ```
using AdaptiveAvgPool1dOptions = AdaptiveAvgPoolOptions<1>;

/// Options for the `AdaptiveAvgPool2d` module.
///
/// Example:
/// ```
/// AdaptiveAvgPool2d model(AdaptiveAvgPool2dOptions({3, 2}));
/// ```
using AdaptiveAvgPool2dOptions = AdaptiveAvgPoolOptions<2>;

/// Options for the `AdaptiveAvgPool3d` module.
///
/// Example:
/// ```
/// AdaptiveAvgPool3d model(AdaptiveAvgPool3dOptions(3));
/// ```
using AdaptiveAvgPool3dOptions = AdaptiveAvgPoolOptions<3>;

namespace functional {
using AdaptiveAvgPool1dFuncOptions = AdaptiveAvgPool1dOptions;
} // namespace functional
namespace functional {
using AdaptiveAvgPool2dFuncOptions = AdaptiveAvgPool2dOptions;
} // namespace functional
namespace functional {
using AdaptiveAvgPool3dFuncOptions = AdaptiveAvgPool3dOptions;
} // namespace functional

// ============================================================================

/// Options for a `D`-dimensional maxunpool module.
template <size_t D>
struct MaxUnpoolOptions {
  MaxUnpoolOptions(ExpandingArray<D> kernel_size)
      : kernel_size_(kernel_size), stride_(kernel_size) {}

  /// the size of the window to take a max over
  TORCH_ARG(ExpandingArray<D>, kernel_size);

  /// the stride of the window. Default value is `kernel_size
  TORCH_ARG(ExpandingArray<D>, stride);

  /// implicit zero padding to be added on both sides
  TORCH_ARG(ExpandingArray<D>, padding) = 0;
};

/// Options for the `MaxUnpool1d` module.
///
/// Example:
/// ```
/// MaxUnpool1d model(MaxUnpool1dOptions(3).stride(2).padding(1));
/// ```
using MaxUnpool1dOptions = MaxUnpoolOptions<1>;

/// Options for the `MaxUnpool2d` module.
///
/// Example:
/// ```
/// MaxUnpool2d model(MaxUnpool2dOptions(3).stride(2).padding(1));
/// ```
using MaxUnpool2dOptions = MaxUnpoolOptions<2>;

/// Options for the `MaxUnpool3d` module.
///
/// Example:
/// ```
/// MaxUnpool3d model(MaxUnpool3dOptions(3).stride(2).padding(1));
/// ```
using MaxUnpool3dOptions = MaxUnpoolOptions<3>;

// ============================================================================

namespace functional {

/// Options for a `D`-dimensional maxunpool functional.
template <size_t D>
struct MaxUnpoolFuncOptions {
  MaxUnpoolFuncOptions(ExpandingArray<D> kernel_size)
      : kernel_size_(kernel_size), stride_(kernel_size) {}

  /// the size of the window to take a max over
  TORCH_ARG(ExpandingArray<D>, kernel_size);

  /// the stride of the window. Default value is `kernel_size
  TORCH_ARG(ExpandingArray<D>, stride);

  /// implicit zero padding to be added on both sides
  TORCH_ARG(ExpandingArray<D>, padding) = 0;

  /// the targeted output size
  TORCH_ARG(c10::optional<std::vector<int64_t>>, output_size) = c10::nullopt;
};

/// `MaxUnpoolFuncOptions` specialized for 1-D maxunpool.
using MaxUnpool1dFuncOptions = MaxUnpoolFuncOptions<1>;

/// `MaxUnpoolFuncOptions` specialized for 2-D maxunpool.
using MaxUnpool2dFuncOptions = MaxUnpoolFuncOptions<2>;

/// `MaxUnpoolFuncOptions` specialized for 3-D maxunpool.
using MaxUnpool3dFuncOptions = MaxUnpoolFuncOptions<3>;

} // namespace functional

// ============================================================================

/// Options for a `D`-dimensional fractional maxpool module.
template <size_t D>
struct FractionalMaxPoolOptions {
  FractionalMaxPoolOptions(ExpandingArray<D> kernel_size)
      : kernel_size_(kernel_size) {}

  /// the size of the window to take a max over
  TORCH_ARG(ExpandingArray<D>, kernel_size);

  /// the target output size of the image
  TORCH_ARG(c10::optional<ExpandingArray<D>>, output_size) = c10::nullopt;

  /// If one wants to have an output size as a ratio of the input size, this option can be given.
  /// This has to be a number or tuple in the range (0, 1)
  using ExpandingArrayDouble=torch::ExpandingArray<D,double>;
  TORCH_ARG(c10::optional<ExpandingArrayDouble>, output_ratio) = c10::nullopt;

  TORCH_ARG(torch::Tensor, _random_samples) = Tensor();
};

/// Options for the `FractionalMaxPool2d` module.
///
/// Example:
/// ```
/// FractionalMaxPool2d model(FractionalMaxPool2dOptions(5).output_size(1));
/// ```
using FractionalMaxPool2dOptions = FractionalMaxPoolOptions<2>;

/// Options for the `FractionalMaxPool3d` module.
///
/// Example:
/// ```
/// FractionalMaxPool3d model(FractionalMaxPool3dOptions(5).output_size(1));
/// ```
using FractionalMaxPool3dOptions = FractionalMaxPoolOptions<3>;

namespace functional {
using FractionalMaxPool2dFuncOptions = FractionalMaxPool2dOptions;
} // namespace functional
namespace functional {
using FractionalMaxPool3dFuncOptions = FractionalMaxPool3dOptions;
} // namespace functional

// ============================================================================

/// Options for a `D`-dimensional lppool module.
template <size_t D>
struct LPPoolOptions {
  LPPoolOptions(double norm_type, ExpandingArray<D> kernel_size)
      : norm_type_(norm_type), kernel_size_(kernel_size), stride_(kernel_size) {}

  TORCH_ARG(double, norm_type);

  // the size of the window to take an average over
  TORCH_ARG(ExpandingArray<D>, kernel_size);

  // the stride of the window. Default value is `kernel_size`
  TORCH_ARG(ExpandingArray<D>, stride);

  // when True, will use `ceil` instead of `floor` to compute the output shape
  TORCH_ARG(bool, ceil_mode) = false;
};

/// Options for the `LPPool1d` module.
///
/// Example:
/// ```
/// LPPool1d model(LPPool1dOptions(1, 2).stride(5).ceil_mode(true));
/// ```
using LPPool1dOptions = LPPoolOptions<1>;

/// Options for the `LPPool2d` module.
///
/// Example:
/// ```
/// LPPool2d model(LPPool2dOptions(1, std::vector<int64_t>({3, 4})).stride({5, 6}).ceil_mode(true));
/// ```
using LPPool2dOptions = LPPoolOptions<2>;

namespace functional {
using LPPool1dFuncOptions = LPPool1dOptions;
} // namespace functional
namespace functional {
using LPPool2dFuncOptions = LPPool2dOptions;
} // namespace functional

} // namespace nn
} // namespace torch
