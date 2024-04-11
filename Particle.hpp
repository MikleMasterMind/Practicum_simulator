#ifndef _Particle_H_
#define _Particle_H_

#include "Math_vector.hpp"

namespace Box_with_balls {

    class Particle {

        Math_vector coordinates;
        Math_vector velocity;

    public:

        Particle(double x = 0, double y = 0, double vx = 0, double vy = 0);

        Particle(Math_vector c = Math_vector(0, 0), Math_vector v = Math_vector(0, 0));

        Math_vector get_coordinates() const;

        void set_coordinates(const Math_vector& x);

        Math_vector get_velocity() const;

        void set_velocity(const Math_vector& v);

        virtual double get_radius() const = 0;

        virtual double get_inv_mass() const = 0;

        virtual void move(double dt);

        virtual void bound_collision(int up, int down, int left, int rigth) = 0;

        virtual bool collision(const Particle* other) const = 0; // find collision with other

        virtual void resolve_collision(Particle* other) = 0; // chenge its velocity and other's 

    };
}

#endif // ! _Particle_H_