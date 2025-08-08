#include "tensorflow/core/framework/op_kernel.h"

using namespace tensorflow;


template <typename T>
class MyCustomAddOp : public OpKernel {
public:
  explicit MyCustomAddOp(OpKernelConstruction* context) : OpKernel(context) {
    OP_REQUIRES_OK(context, context->GetAttr("add_value", &add_value_));
  }

  void Compute(OpKernelContext* context) override {
    const Tensor& input_tensor = context->input(0);
    Tensor* output_tensor = nullptr;
    OP_REQUIRES_OK(context, context->allocate_output(0, input_tensor.shape(), &output_tensor));

    auto input_flat = input_tensor.flat<T>();
    auto output_flat = output_tensor->flat<T>();

    for (int i = 0; i < input_flat.size(); ++i) {
      output_flat(i) = input_flat(i) + static_cast<T>(add_value_);
    }
  }

private:
  int add_value_;
};


#define REGISTER_KERNEL(TYPE)                                         \
REGISTER_KERNEL_BUILDER(                                            \
Name("MyCustomAdd").Device(DEVICE_CPU).TypeConstraint<TYPE>("T"), \
MyCustomAddOp<TYPE>)

REGISTER_KERNEL(int32);
REGISTER_KERNEL(float);
REGISTER_KERNEL(double);

#undef REGISTER_KERNEL
