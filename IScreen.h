#pragma once
class IScreen {
public:
    virtual void Show() = 0;
    virtual ~IScreen() = default;
};