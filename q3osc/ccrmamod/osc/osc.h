//
// C++ Interface: osc
//
// Description:
//
//
// Author: Robert Hamilton <>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#if defined(__cplusplus) || defined(_cplusplus)
   extern "C" {
#endif

typedef struct {
  char *hostname;
  char *port;
  int clientnum;
  float origin[3];
  int pm_flags;
  int weapon;
  int weaponstate;
  int jumppad_ent;
  int damageEvent;
  int damageYaw;
  int damagePitch;
  int damageCount;
  int surfaceFlags;
  int groundEntityNum;
  char *classname;
  char *hostnames[20]; // rkh - added array of client IPs
//	int clientnum;
//	float origin1;
//	float origin2;
//	float origin3;
//          char name[64];
//         char course[128];
//          int age;
//          int year;
} osc_client_vars;

typedef struct {
  char *hostname;
  char *port;
  char *msg;
  char *hostnames[20]; // rkh - added array of client IPs

} osc_misc_vars;


//MZ
typedef struct {
  char *hostname;
  char *port;
  char *victim;
  char *killer;
  int  methodOfDeath;
  int  splashMethodOfDeath;
  char *lastkilled;	// last client that this client killed
  char   *lasthurt;	// last client that damaged this client
  int   lasthurt_mod;		// type of damage the client did
  int team;
  int image;
  int excellent;
  char *hostnames[20]; // rkh - added array of client IPs

} osc_death_vars;

typedef struct {
  char *hostname;
  char *port;
   //team info variables
  //char *team;
  int team;
  //int			location;
  int			captures;
  int			basedefense;
  int			carrierdefense;
  int			flagrecovery;
  int			fragcarrier;
  int			assists;
  float		lasthurtcarrier;
  float		lastreturnedflag;
  float		flagsince;
  float		lastfraggedcarrier;
  int       almostCapture;
  int       carryingOwnFlag;
  int       carryingEnemyFlag;
  char *hostnames[20]; // rkh - added array of client IPs

} osc_team_vars;


typedef struct {
  char *hostname;
  char *port;
  int ownernum;
  int targetnum;
  int bounce;
  int explode;
  float projectilenum;
  float origin[3];
  char *classname;
  char *hostname1;
  char *hostname2;
  char *hostname3;
  char *hostname4;
  char *hostname5;
} osc_projectile_vars;

//void	sendOSCmessage(int clientno, char *hostname, char *portnumber);
void	sendOSCbundle(osc_client_vars currentClient);
void	sendOSCmessage(osc_client_vars currentClient);

void	sendOSCbundle_projectile(osc_projectile_vars currentProjectile);
void	sendOSCmessage_projectile(osc_projectile_vars currentProjectile); //, char *type);

void sendOSCmessage_misc(osc_misc_vars currentClient);
void sendOSCmessage_death(osc_death_vars currentClient);
void sendOSCmessage_team(osc_team_vars teamData);

/*
class fooClass
{
	public:
	  fooClass();
	  ~fooClass();

	private:
	  int number;
};
*/

//class ExamplePacketListener : public osc::OscPacketListener
//{

//}

#if defined(__cplusplus) || defined(_cplusplus)
   }
#endif
