#pragma once

#include <stdexcept>
using std::runtime_error;

class NonExistingKeyException : public runtime_error
{
public:

	NonExistingKeyException::NonExistingKeyException()
		: runtime_error("Key Not Found") {}

};

class DuplicateKeyException : public runtime_error
{
public:

	DuplicateKeyException::DuplicateKeyException()
		: runtime_error("Key Already Exists ") {}

};
