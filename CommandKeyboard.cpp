#include "CommandKeyboard.h"


void CommandKeyboard::insert(const InputCommand& command, const int& at)
{
    keyboard.insert(std::pair<int, InputCommand>(at, command));
}

void CommandKeyboard::run(const int& key) const
{
    auto element = keyboard.find(key);
    if (element != keyboard.end())
    {
        if (keyboard.find(key)->second.isSet())
        {
            keyboard.find(key)->second.run();
        }
    }
}