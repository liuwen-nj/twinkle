#ifndef MPHONEFORM_UI_H
#define MPHONEFORM_UI_H
#include <QMainWindow>
#include "ui_mphoneform.h"
#include "phone.h"
#include "dtmfform.h"
#include "inviteform.h"
#include "redirectform.h"
#include "termcapform.h"
#include "srvredirectform.h"
#include "userprofileform.h"
#include "transferform.h"
#include "syssettingsform.h"
#include "logviewform.h"
#include "historyform.h"
#include "selectuserform.h"
#include "selectprofileform.h"
#include <QEvent>
#include <Q3PopupMenu>
#include <Q3ListViewItem>
#include <QSystemTrayIcon>
#include "im/msg_session.h"
#include "messageformview.h"
#include "buddylistview.h"
#include "diamondcard.h"

class t_phone;
extern t_phone *phone;

class MphoneForm : public Q3MainWindow, public Ui::MphoneForm
{
Q_OBJECT
public:
	MphoneForm(QWidget* parent, const char * name, Qt::WindowFlags f);
	~MphoneForm();

public:
	QString getMWIStatus( const t_mwi & mwi, bool & msg_waiting ) const;
	QSystemTrayIcon * getSysTray();
	bool getViewDisplay();
	bool getViewBuddyList();
	bool getViewCompactLineStatus();
public slots:
	void closeEvent( QCloseEvent * e );
	void fileExit();
	void display( const QString & s );
	void displayHeader();
	void showLineTimer( int line );
	void showLineTimer1();
	void showLineTimer2();
	void updateLineTimer( int line );
	void updateLineEncryptionState( int line );
	void updateLineStatus( int line );
	void updateState();
	void updateRegStatus();
	void flashMWI();
	void updateMwi();
	void updateServicesStatus();
	void updateMissedCallStatus( int num_missed_calls );
	void updateSysTrayStatus();
	void updateMenuStatus();
	void updateDiamondcardMenu();
	void removeDiamondcardAction( int & id );
	void removeDiamondcardMenu( Q3PopupMenu * & menu );
	void phoneRegister();
	void do_phoneRegister( list<t_user *> user_list );
	void phoneDeregister();
	void do_phoneDeregister( list<t_user *> user_list );
	void phoneDeregisterAll();
	void do_phoneDeregisterAll( list<t_user *> user_list );
	void phoneShowRegistrations();
	void phoneInvite( t_user * user_config, const QString & dest, const QString & subject, bool anonymous );
	void phoneInvite( const QString & dest, const QString & subject, bool anonymous );
	void phoneInvite();
	void do_phoneInvite( t_user * user_config, const QString & display, const t_url & destination, const QString & subject, bool anonymous );
	void phoneRedial( void );
	void phoneAnswer();
	void phoneAnswerFromSystrayPopup();
	void phoneBye();
	void phoneReject();
	void phoneRejectFromSystrayPopup();
	void phoneRedirect( const list<string> & contacts );
	void phoneRedirect();
	void do_phoneRedirect( const list<t_display_url> & destinations );
	void phoneTransfer( const string & dest, t_transfer_type transfer_type );
	void phoneTransfer();
	void do_phoneTransfer( const t_display_url & destination, t_transfer_type transfer_type );
	void do_phoneTransferLine();
	void phoneHold( bool on );
	void phoneConference();
	void phoneMute( bool on );
	void phoneTermCap( const QString & dest );
	void phoneTermCap();
	void do_phoneTermCap( t_user * user_config, const t_url & destination );
	void phoneDTMF();
	void sendDTMF( const QString & digits );
	void startMessageSession( void );
	void startMessageSession( t_buddy * buddy );
	void phoneConfirmZrtpSas( int line );
	void phoneConfirmZrtpSas();
	void phoneResetZrtpSasConfirmation( int line );
	void phoneResetZrtpSasConfirmation();
	void phoneEnableZrtp( bool on );
	void phoneZrtpGoClearOk( unsigned short line );
	void line1rbChangedState( bool on );
	void line2rbChangedState( bool on );
	void actionLine1Toggled( bool on );
	void actionLine2Toggled( bool on );
	void srvDnd( bool on );
	void srvDnd();
	void do_srvDnd_enable( list<t_user *> user_list );
	void do_srvDnd_disable( list<t_user *> user_list );
	void srvAutoAnswer( bool on );
	void srvAutoAnswer();
	void do_srvAutoAnswer_enable( list<t_user *> user_list );
	void do_srvAutoAnswer_disable( list<t_user *> user_list );
	void srvRedirect();
	void do_srvRedirect( t_user * user_config, const list<t_display_url> & always, const list<t_display_url> & busy, const list<t_display_url> & noanswer );
	void about();
	void aboutQt();
	void manual();
	void editUserProfile();
	void editSysSettings();
	void selectProfile();
	void newUsers( const list<string> & profiles );
	void updateUserComboBox();
	void updateSipUdpPort();
	void updateRtpPorts();
	void updateStunSettings( t_user * user_config );
	void updateAuthCache( t_user * user_config, const string & realm );
	void unsubscribeMWI( t_user * user_config );
	void subscribeMWI( t_user * user_config );
	void viewLog();
	void updateLog( bool log_zapped );
	void viewHistory();
	void updateCallHistory();
	void quickCall();
	void addToCallComboBox( const QString & destination );
	void showAddressBook();
	void selectedAddress( const QString & address );
	void enableCallOptions( bool enable );
	void keyPressEvent( QKeyEvent * e );
	void mouseReleaseEvent( QMouseEvent * e );
	void processLeftMouseButtonRelease( QMouseEvent * e );
	void processRightMouseButtonRelease( QMouseEvent * e );
	void processCryptLabelClick( int line );
	void popupMenuVoiceMail( const QPoint & pos );
	void popupMenuVoiceMail( void );
	void showDisplay( bool on );
	void showBuddyList( bool on );
	void showCompactLineStatus( bool on );
	void populateBuddyList();
	void showBuddyListPopupMenu( Q3ListViewItem * item, const QPoint & pos );
	void doCallBuddy();
	void doMessageBuddy( Q3ListViewItem * qitem );
	void doMessageBuddy();
	void doEditBuddy();
	void doDeleteBuddy();
	void doAddBuddy();
	void doAvailabilityOffline();
	void doAvailabilityOnline();
	void DiamondcardSignUp();
	void newDiamondcardUser( const QString & filename );
	void DiamondcardAction( t_dc_action action, int userIdx );
	void DiamondcardRecharge( int userIdx );
	void DiamondcardBalanceHistory( int userIdx );
	void DiamondcardCallHistory( int userIdx );
	void DiamondcardAdminCenter( int userIdx );

private:
	void init();
	void destroy();
	QString lineSubstate2str( int line );

private:
	QTimer tmrFlashMWI;
	GetAddressForm *getAddressForm;
	SelectProfileForm *selectProfileForm;
	SelectUserForm *selectUserForm;
	HistoryForm *historyForm;
	TransferForm *transferForm;
	UserProfileForm *userProfileForm;
	SrvRedirectForm *srvRedirectForm;
	TermCapForm *termCapForm;
	RedirectForm *redirectForm;
	InviteForm *inviteForm;
	DtmfForm *dtmfForm;
	SysSettingsForm *sysSettingsForm;
	QStringList displayContents;
	LogViewForm *logViewForm;
	QSystemTrayIcon *sysTray;
	QTimer *lineTimer1;
	QTimer *lineTimer2;
	QTimer *hideLineTimer1;
	QTimer *hideLineTimer2;
	bool viewDisplay;
	bool viewCompactLineStatus;
	bool mwiFlashStatus;
	Q3PopupMenu *buddyPopupMenu;
	Q3PopupMenu *buddyListPopupMenu;
	Q3PopupMenu *changeAvailabilityPopupMenu;
	bool viewBuddyList;

};

#endif
