# Polymorphism in C++

## Aim
To demonstrate runtime polymorphism using a payment system with cash and mobile-money payments.

## OOP Concepts Used

1. **Classes and objects:** `Payment`, `CashPayment`, and `MobileMoneyPayment` are classes. The objects `cash` and `mobileMoney` represent different payment methods.
2. **Inheritance:** Both `CashPayment` and `MobileMoneyPayment` publicly inherit from `Payment`.
3. **Polymorphism:** The same call, `payment->processPayment()`, produces different output depending on the actual object to which the base-class pointer refers.
4. **Virtual function:** `processPayment()` is declared `virtual` in the base class. This enables C++ to select the appropriate overridden function at runtime.
5. **Function overriding:** Each derived class provides its own implementation of `processPayment()` and uses `override` to help the compiler detect signature mistakes.
6. **Base-class pointer:** A `Payment*` pointer can point to a `CashPayment` object or a `MobileMoneyPayment` object.
7. **Virtual destructor:** The base class has a virtual destructor, which is good practice when a class is intended to be used polymorphically.

## Algorithm

1. Define a base class named `Payment` with a virtual function called `processPayment()`.
2. Define `CashPayment` and `MobileMoneyPayment` as derived classes.
3. Override `processPayment()` in each derived class so each payment method has different behaviour.
4. Create one object of each derived class.
5. Declare a pointer of type `Payment*`.
6. Make the pointer refer to the `CashPayment` object and call `processPayment()`.
7. Make the same pointer refer to the `MobileMoneyPayment` object and call the same function.
8. Observe that the output changes according to the object being referenced, then terminate the program.


![alt text](image-1.png)





**Explanation:** The pointer has the base type `Payment*`, but the virtual function call is resolved at runtime using the actual object type. Thus, the same call can perform different actions.

## Possible Error Points

- **Forgetting `virtual`:** Without a virtual base-class function, calls through a base-class pointer do not demonstrate the required runtime polymorphism.
- **Incorrect function signature:** The derived function must match the base function's name, parameters, and `const` qualification. The `override` keyword helps catch mismatches.
- **Pointing to the wrong object:** Ensure the pointer is assigned `&cash` or `&mobileMoney` before calling the function.
- **Null pointer:** Calling a member function through a null pointer causes undefined behaviour. This program assigns a valid object address before each call.
- **Object lifetime:** Do not use a pointer after the object it points to has been destroyed. Both objects in this program remain alive during the calls.
- **Missing headers:** Include `<iostream>` for output. `<string>` is included here but is not required by this particular example.
- **Confusing overloading and overriding:** Overriding replaces inherited virtual-function behaviour in a derived class; overloading uses the same function name with different parameter lists.

## Compilation and Execution

With a C++ compiler such as g++, run:

```bash
g++ -std=c++17 polymorphism.cpp -o polymorphism
./polymorphism
```

On Windows Command Prompt, run `polymorphism.exe` after compilation.
