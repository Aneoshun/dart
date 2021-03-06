/*
 * Copyright (c) 2011-2019, The DART development contributors
 * All rights reserved.
 *
 * The list of contributors can be found at:
 *   https://github.com/dartsim/dart/blob/master/LICENSE
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#include <dart/dart.hpp>
#include <pybind11/pybind11.h>
#include "eigen_geometry_pybind.h"
#include "eigen_pybind.h"

namespace dart {
namespace python {

void JacobianNode(pybind11::module& m)
{
  ::pybind11::class_<
      dart::dynamics::JacobianNode,
      dart::dynamics::Frame,
      dart::dynamics::Node,
      std::shared_ptr<dart::dynamics::JacobianNode>>(m, "JacobianNode")
      .def(
          "getIK",
          +[](dart::dynamics::JacobianNode* self)
              -> std::shared_ptr<dart::dynamics::InverseKinematics> {
            return self->getIK();
          })
      .def(
          "getIK",
          +[](dart::dynamics::JacobianNode* self, bool createIfNull)
              -> std::shared_ptr<dart::dynamics::InverseKinematics> {
            return self->getIK(createIfNull);
          },
          ::pybind11::arg("createIfNull"))
      .def(
          "getOrCreateIK",
          +[](dart::dynamics::JacobianNode* self)
              -> std::shared_ptr<dart::dynamics::InverseKinematics> {
            return self->getOrCreateIK();
          })
      .def(
          "clearIK",
          +[](dart::dynamics::JacobianNode* self) { self->clearIK(); })
      .def(
          "dependsOn",
          +[](const dart::dynamics::JacobianNode* self,
              std::size_t _genCoordIndex) -> bool {
            return self->dependsOn(_genCoordIndex);
          },
          ::pybind11::arg("genCoordIndex"))
      .def(
          "getNumDependentGenCoords",
          +[](const dart::dynamics::JacobianNode* self) -> std::size_t {
            return self->getNumDependentGenCoords();
          })
      .def(
          "getDependentGenCoordIndex",
          +[](const dart::dynamics::JacobianNode* self,
              std::size_t _arrayIndex) -> std::size_t {
            return self->getDependentGenCoordIndex(_arrayIndex);
          },
          ::pybind11::arg("arrayIndex"))
      .def(
          "getNumDependentDofs",
          +[](const dart::dynamics::JacobianNode* self) -> std::size_t {
            return self->getNumDependentDofs();
          })
      .def(
          "getChainDofs",
          +[](const dart::dynamics::JacobianNode* self)
              -> const std::vector<const dart::dynamics::DegreeOfFreedom*> {
            return self->getChainDofs();
          })
      .def(
          "getJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::Jacobian {
            return self->getJacobian(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset) -> dart::math::Jacobian {
            return self->getJacobian(_offset);
          },
          ::pybind11::arg("offset"))
      .def(
          "getJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::Jacobian {
            return self->getJacobian(_offset, _inCoordinatesOf);
          },
          ::pybind11::arg("offset"),
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getWorldJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset) -> dart::math::Jacobian {
            return self->getWorldJacobian(_offset);
          },
          ::pybind11::arg("offset"))
      .def(
          "getLinearJacobian",
          +[](const dart::dynamics::JacobianNode* self)
              -> dart::math::LinearJacobian {
            return self->getLinearJacobian();
          })
      .def(
          "getLinearJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::LinearJacobian {
            return self->getLinearJacobian(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getLinearJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset) -> dart::math::LinearJacobian {
            return self->getLinearJacobian(_offset);
          },
          ::pybind11::arg("offset"))
      .def(
          "getLinearJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::LinearJacobian {
            return self->getLinearJacobian(_offset, _inCoordinatesOf);
          },
          ::pybind11::arg("offset"),
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getAngularJacobian",
          +[](const dart::dynamics::JacobianNode* self)
              -> dart::math::AngularJacobian {
            return self->getAngularJacobian();
          })
      .def(
          "getAngularJacobian",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::AngularJacobian {
            return self->getAngularJacobian(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getJacobianSpatialDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::Jacobian {
            return self->getJacobianSpatialDeriv(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getJacobianSpatialDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset) -> dart::math::Jacobian {
            return self->getJacobianSpatialDeriv(_offset);
          },
          ::pybind11::arg("offset"))
      .def(
          "getJacobianSpatialDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::Jacobian {
            return self->getJacobianSpatialDeriv(_offset, _inCoordinatesOf);
          },
          ::pybind11::arg("offset"),
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getJacobianClassicDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::Jacobian {
            return self->getJacobianClassicDeriv(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getJacobianClassicDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset) -> dart::math::Jacobian {
            return self->getJacobianClassicDeriv(_offset);
          },
          ::pybind11::arg("offset"))
      .def(
          "getJacobianClassicDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::Jacobian {
            return self->getJacobianClassicDeriv(_offset, _inCoordinatesOf);
          },
          ::pybind11::arg("offset"),
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getLinearJacobianDeriv",
          +[](const dart::dynamics::JacobianNode* self)
              -> dart::math::LinearJacobian {
            return self->getLinearJacobianDeriv();
          })
      .def(
          "getLinearJacobianDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::LinearJacobian {
            return self->getLinearJacobianDeriv(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getLinearJacobianDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset) -> dart::math::LinearJacobian {
            return self->getLinearJacobianDeriv(_offset);
          },
          ::pybind11::arg("offset"))
      .def(
          "getLinearJacobianDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const Eigen::Vector3d& _offset,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::LinearJacobian {
            return self->getLinearJacobianDeriv(_offset, _inCoordinatesOf);
          },
          ::pybind11::arg("offset"),
          ::pybind11::arg("inCoordinatesOf"))
      .def(
          "getAngularJacobianDeriv",
          +[](const dart::dynamics::JacobianNode* self)
              -> dart::math::AngularJacobian {
            return self->getAngularJacobianDeriv();
          })
      .def(
          "getAngularJacobianDeriv",
          +[](const dart::dynamics::JacobianNode* self,
              const dart::dynamics::Frame* _inCoordinatesOf)
              -> dart::math::AngularJacobian {
            return self->getAngularJacobianDeriv(_inCoordinatesOf);
          },
          ::pybind11::arg("inCoordinatesOf"))
      // .def("notifyJacobianUpdate", +[](dart::dynamics::JacobianNode *self) {
      // self->notifyJacobianUpdate(); })
      .def(
          "dirtyJacobian",
          +[](dart::dynamics::JacobianNode* self) { self->dirtyJacobian(); })
      // .def("notifyJacobianDerivUpdate", +[](dart::dynamics::JacobianNode
      // *self) { self->notifyJacobianDerivUpdate(); })
      .def("dirtyJacobianDeriv", +[](dart::dynamics::JacobianNode* self) {
        self->dirtyJacobianDeriv();
      });
}

} // namespace python
} // namespace dart
