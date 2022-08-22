/*
** This file is part of the Interactive Medical Simulation Toolkit (iMSTK)
** iMSTK is distributed under the Apache License, Version 2.0.
** See accompanying NOTICE for details.
*/

#pragma once

#include "imstkCollisionInteraction.h"
#include "imstkMacros.h"

namespace imstk
{
class PbdObject;

///
/// \class PbdObjectCollision
///
/// \brief This class defines a collision interaction between two PbdObjects
/// or PbdObject & CollidingObject
///
class PbdObjectCollision : public CollisionInteraction
{
public:
    ///
    /// \brief Constructor for PbdObject-PbdObject or PbdObject-CollidingObject collisions
    ///
    PbdObjectCollision(std::shared_ptr<PbdObject> obj1, std::shared_ptr<CollidingObject> obj2,
                       std::string cdType = "");

    ~PbdObjectCollision() override = default;

    IMSTK_TYPE_NAME(PbdObjectCollision)

    void setRestitution(const double restitution);
    const double getRestitution() const;

    void setFriction(const double friction);
    const double getFriction() const;

    ///
    /// \brief Setup connectivity of task graph
    ///
    void initGraphEdges(std::shared_ptr<TaskNode> source, std::shared_ptr<TaskNode> sink) override;

protected:
    // Steps introduced in interaction
    std::shared_ptr<TaskNode> m_collisionSolveNode    = nullptr;
    std::shared_ptr<TaskNode> m_correctVelocitiesNode = nullptr;
};
} // namespace imstk