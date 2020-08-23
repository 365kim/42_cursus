<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '<Xn6W`UF[`5Q+ 55>~+p_$SatlEU8(_p-2Xds;KJ$t6p),LSZ_-[s_nWh>.efAJI');
define('SECURE_AUTH_KEY',  '`xR|p+F6c7]+F3`Jd2;|_SVScJ[r7xxe`EL]k<dJT(.IVkG{NX=%!&ZH:E3xQlP0');
define('LOGGED_IN_KEY',    'UCdLHE]U1Kl{9b:}6r1c)1m-FElG#|(~-cen?-!!sJUL5([,9eQkaV4b5Y=VftK?');
define('NONCE_KEY',        '>v3MCX&QA#Ai9F`c|14A-S40B$)O;^q0&L%vo>>9v9_i=!+>VPiJLQ}dr..7Hn*:');
define('AUTH_SALT',        '!T$x;YpBMymew8jvJ1+QL.oG)T/jMh]vC8]@O>Ghjsgih*G1!E!BO_7U;d*mO+jG');
define('SECURE_AUTH_SALT', 'qnIPUJy4Vsg|+!9Rx-!4qW/<n$CI):$NZq<(@~QE-V;nheeXbDmpm+zcC%uLNX0K');
define('LOGGED_IN_SALT',   '4O0oPQ7`B1@f&~6x4!6K>WQvo>=~#gP|mjUJOdmB>UzxlmmC,];m6au2-E E%-|Z');
define('NONCE_SALT',       'l#k*QizO8Sq(M+60l89Er{-t/Pw8fu9Oz3s*q) )G`]j{TSJiB(N3ifM%.p##Bbr');


/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true tao enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
