#include "PBDTimeIntegration.h"

using namespace sofa::simulation::PBDSimulation;

// ----------------------------------------------------------------------------------------------
void PBDTimeIntegration::semiImplicitEuler(
    const Real h,
    const Real mass,
    Vector3r &position,
    Vector3r &velocity,
    const Vector3r &acceleration)
{
    if (mass != 0.0)
    {
        velocity += acceleration * h;
        position += velocity * h;
    }
}

// ----------------------------------------------------------------------------------------------
void PBDTimeIntegration::semiImplicitEulerRotation(
    const Real h,
    const Real mass,
    const Matrix3r &invInertiaW,
    Quaternionr &rotation,
    Vector3r &angularVelocity,
    const Vector3r &torque)
{
    if (mass != 0.0)
    {
        // simple form without nutation effect
        angularVelocity += h * invInertiaW * torque;

        Quaternionr angVelQ(0.0, angularVelocity[0], angularVelocity[1], angularVelocity[2]);
        rotation.coeffs() += h * 0.5 * (angVelQ * rotation).coeffs();
        rotation.normalize();
    }
}

// ----------------------------------------------------------------------------------------------
void PBDTimeIntegration::velocityUpdateFirstOrder(
    const Real h,
    const Real mass,
    const Vector3r &position,
    const Vector3r &oldPosition,
    Vector3r &velocity)
{
    if (mass != 0.0)
        velocity = (1.0 / h) * (position - oldPosition);
}

// ----------------------------------------------------------------------------------------------
void PBDTimeIntegration::angularVelocityUpdateFirstOrder(
    const Real h,
    const Real mass,
    const Quaternionr &rotation,
    const Quaternionr &oldRotation,
    Vector3r &angularVelocity)
{
    if (mass != 0.0)
    {
        const Quaternionr relRot = (rotation * oldRotation.conjugate());
        angularVelocity = relRot.vec() *(2.0 / h);
    }
}

// ----------------------------------------------------------------------------------------------
void PBDTimeIntegration::velocityUpdateSecondOrder(
    const Real h,
    const Real mass,
    const Vector3r &position,
    const Vector3r &oldPosition,
    const Vector3r &positionOfLastStep,
    Vector3r &velocity)
{
    if (mass != 0.0)
        velocity = (1.0 / h) * (1.5*position - 2.0*oldPosition + 0.5*positionOfLastStep);
}

// ----------------------------------------------------------------------------------------------
void PBDTimeIntegration::angularVelocityUpdateSecondOrder(
    const Real h,
    const Real mass,
    const Quaternionr &rotation,
    const Quaternionr &oldRotation,
    const Quaternionr &rotationOfLastStep,
    Vector3r &angularVelocity)
{
    // ToDo: is still first order
    if (mass != 0.0)
    {
        const Quaternionr relRot = (rotation * oldRotation.conjugate());
        angularVelocity = relRot.vec() *(2.0 / h);
    }
}