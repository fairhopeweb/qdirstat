/*
 *   File name:	kdirstatmain.cpp
 *   Summary:	Main program for QDirStat
 *   License:   GPL V2 - See file LICENSE for details.
 *
 *   Author:	Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
 */


#include <kcmdlineargs.h>
#include <kaboutdata.h>

#include <QDir>
#include "QDirStatApp.h"


static const char *description =
	I18N_NOOP("QDirStat - Directory statistics.\n"
		  "\n"
		  "Shows where all your disk space has gone\n"
		  "and helps you clean it up."
		  "\n"
		  "\n"
		  "\n"
		  "If you have any comments or if you would simply like to tell your opinion\n"
		  "about this program, please use \"Send Feedback Mail\" from the \"Help\" menu.\n"
		  "\n"
		  "Any feedback (even negative!) is appreciated."
		  );


static KCmdLineOptions options[] =
{
    { "+[Dir/URL]", I18N_NOOP("Directory or URL to open"), 0 },
    { 0, 0, 0 }
};

int main(int argc, char *argv[])
{
    KAboutData aboutData( "kdirstat", "QDirStat",
			  VERSION, description, KAboutData::License_GPL,
			  "(c) 1999-2008 Stefan Hundhammer", 0, 0,
			  "Stefan.Hundhammer@gmx.de" );
    
    aboutData.addAuthor( "Stefan Hundhammer",
			 I18N_NOOP("\n"
				   "If you have any comments or if you would simply like to tell\n"
				   "your opinion about this program, please use \n"
				   "\"Send Feedback Mail\" from the \"Help\" menu.\n"
				   "\n"
				   "Any feedback (even negative!) is appreciated." ),
			 "Stefan.Hundhammer@gmx.de",
			 "http://kdirstat.sourceforge.net/" );

    aboutData.addCredit( "SequoiaView Team",
			 I18N_NOOP( "for showing just how useful treemaps really can be." ),
			 0,	// e-mail
			 "http://www.win.tue.nl/sequoiaview" );

    aboutData.addCredit( "Jarke J. van Wijk, Huub van de Wetering, Mark Bruls",
			 I18N_NOOP( "for their papers about treemaps." ),
			 "vanwijk@win.tue.nl",
			 "http://www.win.tue.nl/~vanwijk/" );

    aboutData.addCredit( "Ben Shneiderman",
			 I18N_NOOP( "for his ingenious idea of treemaps -\n"
				    "a truly intuitive way of visualizing tree contents." ),
			 "",	// E-Mail
			 "http://www.cs.umd.edu/hcil/treemaps/" );

    aboutData.setTranslator( "", "" ); // Default KDE templates don't apply - better leave it empty

    KCmdLineArgs::init( argc, argv, &aboutData );
    KCmdLineArgs::addCmdLineOptions( options ); // Add our own options.

    KApplication app;

    
    if ( app.isRestored() )
    {
	RESTORE( QDirStatApp );
    }
    else
    {
	QDirStatApp *kdirstat = new QDirStatApp();
	kdirstat->show();

	KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

	if ( args->count() )
	{
	    // Process command line arguments as URLs or paths to scan

	    QString url = QDir::cleanPath( args->arg( 0 ) );
	    // logDebug() << "Opening " << url.url() << endl;
	    kdirstat->openURL( url );
	}
	else
	{
	    kdirstat->fileAskOpenDir();
	}

	args->clear();
    }

    // logDebug() << "Entering main loop" << endl;

    return app.exec();
}

