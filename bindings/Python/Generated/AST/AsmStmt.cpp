// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AsmStmt.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>
#include <multiplier/Re2.h>

#include <cassert>
#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace {
using T = mx::AsmStmt;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

inline static O *O_cast(void *obj) noexcept {
  return reinterpret_cast<O *>(obj);
}

inline static const O *O_cast(const void *obj) noexcept {
  return reinterpret_cast<const O *>(obj);
}

inline static T *T_cast(void *obj) noexcept {
  return O_cast(obj)->data;
}

inline static const T *T_cast(const void *obj) noexcept {
  return O_cast(obj)->data;
}

}  // namespace
namespace mx {

namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  PyTypeObject * const tp = Py_TYPE(obj);
  if (tp < &(gTypes[554]) || tp >= &(gTypes[557])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      assert(false);
      tp = gType;
      break;

    case mx::MSAsmStmt::static_kind():
      tp = &(gTypes[555]);
      break;

    case mx::GCCAsmStmt::static_kind():
      tp = &(gTypes[556]);
      break;

  }
  auto ret = tp->tp_alloc(tp, 0);
  if (auto obj = O_cast(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

namespace {
static PyTypeObject *InitType(void) noexcept;
}  // namespace

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    gType = InitType();
    if (!gType) {
      return false;
    }
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "AsmStmt", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "generate_assembly_string",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->generate_assembly_string());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::generate_assembly_string"),
    nullptr,
  },
  {
    "assembly_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->assembly_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::assembly_token"),
    nullptr,
  },
  {
    "num_inputs",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_inputs());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::num_inputs"),
    nullptr,
  },
  {
    "inputs",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->inputs());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::inputs"),
    nullptr,
  },
  {
    "is_simple",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_simple());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::is_simple"),
    nullptr,
  },
  {
    "is_volatile",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_volatile());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::is_volatile"),
    nullptr,
  },
  {
    "num_outputs",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_outputs());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::num_outputs"),
    nullptr,
  },
  {
    "outputs",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->outputs());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::outputs"),
    nullptr,
  },
  {
    "output_constraints",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->output_constraints());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::output_constraints"),
    nullptr,
  },
  {
    "num_output_expressions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_output_expressions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::num_output_expressions"),
    nullptr,
  },
  {
    "output_expressions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->output_expressions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::output_expressions"),
    nullptr,
  },
  {
    "input_constraints",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->input_constraints());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::input_constraints"),
    nullptr,
  },
  {
    "num_input_expressions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_input_expressions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::num_input_expressions"),
    nullptr,
  },
  {
    "input_expressions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->input_expressions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::input_expressions"),
    nullptr,
  },
  {
    "clobbers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->clobbers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::AsmStmt::clobbers"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "IN",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Index>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Fragment>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::File>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::AsmStmt::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Token>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Decl>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::optional<mx::Decl>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::optional<mx::Stmt>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::AsmStmt::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 2) {
            auto arg_0 = PythonBinding<mx::Index>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = PythonBinding<mx::EntityId>::from_python(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->by_id(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::AsmStmt::by_id"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from_base(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'from_base'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::AsmStmt::from_base"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::optional<mx::Stmt>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Reference>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation>>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::TokenContext>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::AsmStmt::from"),
  },
  {
    "nth_input",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<uint32_t>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_input(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_input'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::AsmStmt::nth_input"),
  },
  {
    "nth_output",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<uint32_t>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_output(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_output'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::AsmStmt::nth_output"),
  },
  {
    "nth_output_expression",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<uint32_t>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_output_expression(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_output_expression'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::AsmStmt::nth_output_expression"),
  },
  {
    "nth_input_expression",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<uint32_t>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_input_expression(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_input_expression'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::AsmStmt::nth_input_expression"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[554]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.AsmStmt";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::AsmStmt");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[448].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[448]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'AsmStmt.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'AsmStmt.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'AsmStmt' cannot be directly instantiated";
    return -1;

  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx