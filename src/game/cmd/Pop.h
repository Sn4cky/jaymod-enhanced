#ifndef GAME_CMD_POP_H
#define GAME_CMD_POP_H

///////////////////////////////////////////////////////////////////////////////

class Pop : public AbstractBuiltin
{
protected:
    PostAction doExecute( Context& );

public:
    Pop();
    ~Pop();
};

///////////////////////////////////////////////////////////////////////////////

#endif // GAME_CMD_POP_H
