# 3D Ising Model Simulation and Experimental Comparison

## Overview

This project was completed as part of my senior undergraduate physics studies. It implements a three-dimensional Ising Model in C++ using the Metropolis–Hastings algorithm to simulate ferromagnetic phase transitions.

The simulation computes several thermodynamic observables, including magnetization, internal energy, specific heat, and magnetic susceptibility, as functions of temperature. The results are then compared to experimental magnetization data from a cobalt–nickel–iron–carbon–boron (CoNiFeCB) ferromagnetic alloy.

This project demonstrates the use of computational physics and numerical simulation to model phase transitions and validate theoretical predictions against real experimental data.

---

## Scientific Motivation

Ferromagnetic materials exhibit spontaneous magnetization below a critical temperature known as the Curie temperature, $T_C$. Above this temperature, thermal fluctuations disorder the magnetic moments and the material becomes paramagnetic.

The Ising model is one of the most important models in statistical mechanics and condensed matter physics. Despite its simplicity, it captures the essential physics of phase transitions and critical phenomena.

This project investigates how well a simple nearest-neighbor 3D Ising model reproduces experimentally measured magnetization curves.

---

## The Ising Model

Each lattice site contains a spin variable:

$$
s_i \in \{-1, +1\}
$$

where:

- $+1$ represents a spin pointing upward.
- $-1$ represents a spin pointing downward.

The Hamiltonian of the system is:

$$
H = -J \sum_{\langle i,j \rangle} s_i s_j
$$

where:

- $J > 0$ is the ferromagnetic coupling constant.
- $\langle i,j \rangle$ denotes nearest-neighbor pairs.

In the cubic lattice used here, each spin interacts with six nearest neighbors.

---

## Thermodynamic Behavior

### Low Temperature ($T \ll T_C$)

At low temperatures, thermal fluctuations are weak and the system minimizes its energy by aligning neighboring spins. This produces a large net magnetization.

### High Temperature ($T \gg T_C$)

At high temperatures, thermal fluctuations dominate and randomize the spin orientations, causing the magnetization to approach zero.

### Critical Temperature ($T = T_C$)

At the Curie temperature, the system undergoes a second-order phase transition from an ordered ferromagnetic state to a disordered paramagnetic state.

For the three-dimensional Ising model:

$$
\frac{k_B T_C}{J} \approx 4.51
$$

where $k_B$ is Boltzmann's constant.

---

## Monte Carlo Simulation

The simulation uses the Metropolis algorithm to sample spin configurations according to the Boltzmann distribution.

For a proposed spin flip, the change in energy is:

$$
\Delta E = 2 J s_i \sum_{j \in \mathrm{nn}} s_j
$$

where the sum runs over the six nearest neighbors of spin $s_i$.

The spin flip is accepted if:

1. $\Delta E < 0$, meaning the flip lowers the energy, or
2. A random number $r \in [0,1]$ satisfies

$$
r < e^{-\Delta E / (k_B T)}
$$

This acceptance criterion ensures that configurations are sampled with probability proportional to

$$
P \propto e^{-H / (k_B T)}.
$$

---

## Simulation Parameters

| Parameter | Value |
|----------|-------|
| Lattice dimensions | $20 \times 20 \times 20$ |
| Total spins | 8000 |
| Boundary conditions | Periodic |
| Temperature range | 0.5 to 8.0 |
| Monte Carlo sweeps | 2000 per temperature |
| Programming language | C++ |
| Plotting framework | ROOT |

---

## Measured Quantities

### Magnetization

$$
M = \sum_i s_i
$$

The magnetization measures the net alignment of all spins in the lattice.

---

### Internal Energy

$$
U = \langle H \rangle
$$

The internal energy is the ensemble average of the Hamiltonian.

---

### Specific Heat

$$
C_V = \frac{\langle E^2 \rangle - \langle E \rangle^2}{T^2}
$$

The specific heat measures fluctuations in energy and typically exhibits a pronounced peak near the critical temperature.

---

### Magnetic Susceptibility

$$
\chi = \frac{\langle M^2 \rangle - \langle M \rangle^2}{T}
$$

The magnetic susceptibility measures fluctuations in magnetization and also peaks near the phase transition.

---

## Experimental Comparison

The simulation results were compared to experimental magnetization data from a cobalt–nickel–iron–carbon–boron (CoNiFeCB) ferromagnetic alloy.

A ROOT macro was used to:

1. Read the experimental measurements from `magnetization.dat`.
2. Load the simulated magnetization curve.
3. Apply scaling factors to convert the dimensionless simulation output into experimental units.
4. Overlay the theoretical and experimental curves on a single plot.

This comparison demonstrated that the 3D Ising model successfully reproduces the characteristic shape of the experimental magnetization curve and accurately captures the location of the Curie transition.

---

## Key Results

The simulation produced several important results:

- A sharp decrease in magnetization near the critical temperature.
- Peaks in both specific heat and magnetic susceptibility at the phase transition.
- Excellent qualitative agreement with experimental magnetization data.
- Validation of the 3D Ising model as a realistic description of ferromagnetic materials.

---

## Computational Skills Demonstrated

This project involved:

- Statistical mechanics and condensed matter physics.
- Monte Carlo methods and stochastic simulation.
- C++ programming.
- Numerical data analysis.
- Experimental data fitting and comparison.
- Scientific visualization using ROOT.

---

## Relevance to Quantum Computing

The Ising Hamiltonian is also the mathematical foundation of quantum annealing systems such as those developed by D-Wave.

Optimization problems can be mapped to an Ising energy function of the form

$$
E(\mathbf{s}) = -\sum_i h_i s_i - \sum_{i<j} J_{ij} s_i s_j,
$$

where the goal is to find the spin configuration $\mathbf{s}$ that minimizes the energy.

This project provided early hands-on experience with the same theoretical framework that underlies modern quantum optimization hardware.

---

## Author

Christina Nelson  
Senior Undergraduate Physics Project  
Univeristy of Hawaii Manoa
