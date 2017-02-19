#include <bgame/impl.h>

namespace cmd {

///////////////////////////////////////////////////////////////////////////////

HolyShit::HolyShit()
    : AbstractBuiltin( "holyshit" )
{
    __usage << xvalue( "!" + _name );

    __descr << "Holy shit.";
}

///////////////////////////////////////////////////////////////////////////////

HolyShit::~HolyShit()
{
}

///////////////////////////////////////////////////////////////////////////////

AbstractCommand::PostAction
HolyShit::doExecute( Context& txt )
{

	int target = txt._client->gclient.pers.lastkilledby_holy;

	Buffer buf;
	if( target == txt._client->slot ) {
		buf << txt._user.namex << ": ^1HOOOOOOOLY SHIT!!!";
	} else {
		buf << txt._user.namex << ": ^1HOOOOOOOLY SHIT!!! " << xvalue( connectedUsers[target]->namex );
	}

    /*Buffer buf;
	buf << txt._user.namex << ": ^1HOOOOOOOLY SHIT!!! " << xvalue( connectedUsers[target]->namex );*/

    printChat( txt._client, buf, true );
	trap_SendConsoleCommand( EXEC_APPEND, "playsound sound/multikill/holyshit.wav" );

    return PA_NONE;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace cmd
