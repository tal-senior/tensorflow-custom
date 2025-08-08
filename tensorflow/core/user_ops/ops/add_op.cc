#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"

using namespace tensorflow;

REGISTER_OP("MyCustomAdd")
    .Input("input: T")
    .Attr("add_value: int")
    .Output("output: T")
    .Attr("T: {int32, float, double}")
    .SetShapeFn([](shape_inference::InferenceContext* c) {
      c->set_output(0, c->input(0));
      return absl::OkStatus();
    });
