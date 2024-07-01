# `xcc` `debug` Structural macros

In this document I will explain what the (**structural macros**) are.

The (**structural macros**) is an architecture or method for building and controlling shared classes in a simple, unified, and easy way, using only macros.

> This is not a header file or a file for a particular library or concept.
>
> At the moment, I'm currently recording everything in the sections or concepts I'm working on now, so this document location may change later.

---

**Let's say I want to write code like this :**

```cpp
// Include the header file containing the code (structural macros)
#include "node.h"

// [1] : Create a new controller for the nodes
NEW_NODE_CTRL(nodes)

// [2] : Create a new instance class of the node class with automatic registration
NEW_NODE(nodes, node_1) { PRINT("node_1") }
NEW_NODE(nodes, node_2) { PRINT("node_2") }

// Run the registered nodes
int main() { nodes.Run(); }
```

```cpp
> node_1
> node_2
```

**To make this implementation possible we must create the following :**

1. **The Node**

    > The node is the base class to inherit from it

    > I will use the pointer of the class, instead of the class itself

    ```cpp
    class Node
    {
        public :

        // : Name
        virtual const xcc::t_char*  name () const noexcept = 0;

        // : Body
        virtual void                body () const noexcept = 0;
    };
    ```

2. **The Controller**

    > The controller is the way to store the new nodes pointers and handling it

    ```cpp
    class Ctrl
    {
        public :

        // : Name
        const xcc::t_char*  name;

        // : Nodes
        std::vector<Node*>  nodes;

        // : Run
        void Run () { for (auto node : nodes) node->body(); }

        // : Init
        Ctrl (const xcc::t_char* _name) noexcept
        : name { _name }
        { }
    };
    ```

2. **The Creators**

    > The creators is the macro units for creating and registering the nodes

    ```cpp
    // Helpers
    #define OBJ(c,n) c##_##n
    #define TAG(c,n) c##_##n##_node
    #define STR_(s, ...) #s
    #define STR(...) STR_(__VA_ARGS__, )

    // Create a new node
    #define NEW_NODE(c, n)                                              \
                                                                        \
    class OBJ(c,n) : public Node                                        \
    {                                                                   \
        public :                                                        \
                                                                        \
        const xcc::t_char*  name () const noexcept { return STR(n); }   \
        void                body () const noexcept override;            \
        OBJ(c,n)                 () { c.nodes.push_back(this); };       \
    };                                                                  \
                                                                        \
    OBJ(c,n) TAG(c,n);                                                  \
                                                                        \
    c.nodes.push_back(&TAG(c,n));                                       \
                                                                        \
    void  OBJ(c,n)::body () const noexcept

    // Create a new controller
    #define NEW_NODE_CTRL(n) Ctrl n(STR(n));

    ```
**I think this example is enough to explain what I mean when I mention (structural macros)**

> I will use this architecture to build many things like unit tests framework, benchmark framework and many more..

---

All rights reserved to me (Maysara Khaled El-Shewehy).


---

## Related

- **[`xcc` `debug` `Benchmark`](bench.md)**

- **[`xcc` `debug` `Test`](test.md)**

- **[`xcc` `debug`](readme.md)**

- **[`xcc`](../../readme.md)**
