# ⚫ Liskov Substitution Principle (LSP) - SOLID Design Principle

The **Liskov Substitution Principle (LSP)** is the **L** in SOLID principles. It ensures that **subclasses remain completely interchangeable** with their parent classes without altering the correctness of the program.

---

## 🧠 Definition (as per Barbara Liskov)

> *"Objects of a superclass should be replaceable with objects of its subclasses **without breaking the application**."*

---

## ✅ LSP in Simple Words

If a class `S` is a subtype of class `T`, then `T`'s objects should be **replaceable by `S` objects** without any unexpected behavior.

```cpp
T* obj = new S(); // should work exactly like T


🔐 Signature Rule (LSP Compliance)
1️⃣ Method Arguments
Subclass must accept the same or more general arguments (covariance).
Cannot require stricter inputs than base class.
2️⃣ Return Type
Subclass can return the same or a more specific type (covariant return allowed).
3️⃣ Exception Rule
Subclass should not throw new or broader exceptions that the base class doesn’t throw.
This prevents surprises for the calling code.


📏 Property Rule (Object Invariants)
Ensures the internal state of the object is consistent and doesn't break expected behavior.
🔸 Class Invariant
Subclass should preserve all invariants defined in the superclass.
Example: If base class maintains a non-null list, the subclass cannot allow nulls.
🔸 History Constraint (or Mutability Rule)
Subclass must not allow changes to state in a way the base class doesn't. If base object is immutable, subclass cannot become mutable.


🔁 Method Rule
🔹 Precondition (Input Constraint)
Subclass must not strengthen the preconditions. It must accept everything the base method accepted.
🔹 Postcondition (Output Guarantee)
Subclass must not weaken the postconditions.It must guarantee at least what the base method promised, or more.