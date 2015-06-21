The C++ "buck" operator
=======================

Syntactic sugar for a more expressive way of returning multiple values from a function.
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

#### Example: ignoring some values

    string name;

    $(, name) = get_username();

## Remarks:

* it requires C++11
* it's just a wrapper on top of `std::tuple`
* it triggers the GCC warning `dollar-in-identifier-extension`
