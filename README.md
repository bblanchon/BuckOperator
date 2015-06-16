The C++ "buck" operator
=======================

A suggestion for a more expressive way of returning multiple values from a function.
Defines a new syntax, using the dollar sign, to bind multiple values together.

**WARNING**: This is probably a stupid idea, use this at your own risks.

#### Example: declaring a function

    $<int, string> get_username();

#### Example: returning multiple values

    return $(0, "root");

#### Example: assigning the result to variables

	int id;
	string name;

	$(id, name) = get_username();

## Remarks:

* it requires C++11
* it is just a wrap around `std::tie` and `std::tupple`
* it requires that the compiler accept `$` as a valid class name
* it requires that it also allow a `$` macro
