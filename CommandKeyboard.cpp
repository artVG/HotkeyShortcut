#include "CommandKeyboard.h"



void CommandKeyboard::insert(const std::shared_ptr<AbstractFunction> command, const int& at)
{
    auto element = keyboard.find(at);
    if (element == keyboard.end())
    {
        keyboard.insert(std::pair<int, std::shared_ptr<AbstractFunction>>(at, command));
    }
}

void CommandKeyboard::run(const int& key) const
{
    auto element = keyboard.find(key);
    if (element != keyboard.end())
    {
        
        keyboard.find(key)->second->run();
    }
}