#include "InputCommand.h"



InputCommand::InputCommand(const std::vector<INPUT> data, const CommandFunction function)
    :data{ data }, function{ function }
{}

InputCommand::InputCommand()
    :data{ }, function{ }
{}

void InputCommand::run() const
{
    function(data.data(), data.size());
}

bool InputCommand::isSet() const
{
    return function ? true : false;
}



