# 🧘 Philosophers

<p align="center">
	<img src="img/philosopherse.png" alt="philo Badge" width="15%">
</p>

## 📝 Table of Contents
- [Introduction](#introduction)
- [The Dining Philosophers Problem](#the-dining-philosophers-problem)
- [Rules of the Simulation](#rules-of-the-simulation)
- [Program Usage](#program-usage)
- [Credits](#Credits)
- [License](#License)

---

## 📖 Introduction
The **Philosophers** project is part of the 42 curriculum and is designed to introduce students to the concepts of **multithreading**, **synchronization**, and **deadlock prevention**. It simulates the famous "Dining Philosophers Problem," a classic problem in computer science that explores resource sharing and concurrency.

---

## 🍽️ The Dining Philosophers Problem
Imagine five philosophers sitting around a circular table. Each philosopher alternates between three states:
- **Thinking** 🧠
- **Eating** 🍝
- **Sleeping** 🛌

To eat, a philosopher needs two forks (one on their left and one on their right). However, there are only five forks available, one between each pair of philosophers. This creates a challenge: how can the philosophers eat without causing a deadlock or starvation?

---

## 📜 Rules of the Simulation
1. **Philosophers' Actions**:
   - A philosopher can **think**, **take forks**, **eat**, or **sleep**.
   - To eat, a philosopher must pick up both forks (left and right).

2. **Simulation Parameters**:
   - `number_of_philosophers`: Total number of philosophers (and forks).
   - `time_to_die`: Time (in ms) a philosopher can live without eating.
   - `time_to_eat`: Time (in ms) it takes for a philosopher to eat.
   - `time_to_sleep`: Time (in ms) a philosopher spends sleeping.
   - `[number_of_times_each_philosopher_must_eat]` (optional): If provided, the simulation stops when all philosophers have eaten this many times.


3. **Parameters Rules**:
   - The `number_of_philosophers` must not exceed 200.
   - All the `times` values must not be bellow 60 ms.
   - All the arguments given to the program must be strictly positive and numeric values.

4. **Philosopher Death**:
   - If a philosopher does not eat within `time_to_die`, they die, and the simulation ends. The message must be displayed within 10 ms after a philo dies. _(first argument in the printed message)_

5. **No Deadlocks**:
   - The program must ensure that no deadlocks occur during the simulation.

6. **No Data Races**
	- Ensure that the thread accessing a data does not conflict with another thread.
---

## 💻 Program Usage
### Compilation
To compile the program, run:
```bash
make
```

To run the program : 

```bash
./philo 5 800 200 200 7
```

The message is formated as follows : 
- [`duration_in_ms`] [`philo_id`] [`action`]

_eg:_
- _0 1 has taken a fork_  
- _400 3 is thinking_ 

## ➡️ Credits

This project was completed as part of the 42 curriculum. For more information, visit [42 Network](https://www.42.fr/).

## ⚖️ License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
