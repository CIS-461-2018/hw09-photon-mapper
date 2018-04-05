Photon Mapper
======================

**University of Pennsylvania, CIS 561: Advanced Computer Graphics, Homework 9**

Overview
------------
You will implement a basic photon mapper using the k-d tree you wrote last week
to store your photons.

Provided code
------
You will once again work with your path tracer base code. We have provided
updates to some of the files previously included, as well as some new files.
Please copy these files into your existing path tracer.

Migrating your k-d tree code (5 points)
---------------
Implement the `build` and `particlesInSphere` functions of the provided
`KDTree` class. Note that because this k-d tree stores `Photons` rather than
just `glm::vec3`s, you'll have to modify your code slightly to refer to the
`pos` member of the `Photon`s.

`PhotonMapper::Render` (50 points)
----------
Implement the preprocessing half of `PhotonMapper::Render()` so that it
casts `Photon`s from each light source, bounces them through the scene, and
stores their bounce data in `PhotonMapper`'s `photons` vector. Remember, tracing
a photon is just like tracing a ray, so when a photon interacts with a material,
its energy is diminished by `f`, `AbsDot`, and `pdf`. You should implement
Russian Roulette termination for your photons, tracking the throughput of your
photon path as it travels. However, unlike your `FullLightingIntegrator`, you
should not boost the power of a photon if it passes a Russian Roulette check;
you're not casting a set of photons in the same direction like you would camera
rays, so it's not as accurate to model a photon path as "counting as" the
contribution of early-terminated paths. You should implement this function
iteratively so as to more easily track throughput, and to save on stack space.

`PhotonMapper::Li` (45 points)
------------
For each ray cast through a pixel, compute the direct illumination on the
point of intersection just as you would in a `DirectLightingIntegrator`. Then,
estimate the indirect illumination at that point by gathering all the photons
in your defined search radius and summing the results of their individual
light transport equation evaluations, then dividing the sum by the area of the
space in which you searched for photons. Remember that a photon represents both
the `Li` term and the `wi` term of the LTE. Since you already bounced photon
paths in `Render`, there's no need for iteration or recursion in `Li`.


If you're wondering why we aren't requiring some of the more advanced photon
mapping features discussed in class (e.g. Gaussian filtering), it's because you
will have the option to expand your photon mapper with additional
optimizations and features during the final project if you so choose.


Submitting your project
--------------
Along with your project code, make sure that you fill out this `README.md` file
with your name and PennKey.

Rather than uploading a zip file to Canvas, you will simply submit a link to
the committed version of your code you wish us to grade. If you click on the
__Commits__ tab of your repository on Github, you will be brought to a list of
commits you've made. Simply click on the one you wish for us to grade, then copy
and paste the URL of the page into the Canvas submission form.
