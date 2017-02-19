#include <bgame/impl.h>

namespace cmd {

///////////////////////////////////////////////////////////////////////////////

Sudo::Sudo()
    : AbstractBuiltin( "sudo" )
{
    __usage << xvalue( "!" + _name ) << ' ' << xvalue( "PLAYER" ) << ' ' << xvalue( "MESSAGE" );
    __descr << "Make a player say something.";
}

///////////////////////////////////////////////////////////////////////////////

Sudo::~Sudo()
{
}

///////////////////////////////////////////////////////////////////////////////

AbstractCommand::PostAction
Sudo::doExecute( Context& txt )
{
    if (txt._args.size() < 3)
        return PA_USAGE;

    Client* target;
    if (lookupPLAYER( txt._args[1], txt, target ))
        return PA_ERROR;
	gentity_t *ent = g_entities + target->gentity.client->ps.clientNum;

	string message = "";
	for(int i = 2; i < txt._args.size(); ++i) {
		message += txt._args[i] + " ";
	}

	G_Say( ent, NULL, SAY_ALL, message.c_str() );

    return PA_NONE;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace cmd
