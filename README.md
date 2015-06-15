The C++ "buck" operator
=======================

An suggestion for a more expressive way of returning multiple values from a function.
Defines a new syntax, using the dollar sign, to bind multiple values together.

**SAFETY WARNING**: When I showed that to my boss, he clearly stated that this was one of the stupidest idea one could ever have, and that no C++ would want to use that.

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
