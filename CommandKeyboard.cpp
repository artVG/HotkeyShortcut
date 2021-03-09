#include "CommandKeyboard.h"



void CommandKeyboard::insert(const std::shared_ptr<AbstractFunction> command, const int& at)
{
    // check if key is already set
    auto element = keyboard.find(at);
    if (element == keyboard.end())
    {
        // insert if position is empty
        keyboard.insert(std::pair<int, std::shared_ptr<AbstractFunction>>(at, command));
    }
}

void CommandKeyboard::run(const int& key) const
{
    // check if key is set
    auto element = keyboard.find(key);
    if (element != keyboard.end())
    {
        // run hot key command
        keyboard.find(key)->second->run();
    }
}