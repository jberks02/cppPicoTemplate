# cppPicoTemplate
C++ on the RaspberryPiPico template project

follow guides at:

https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/

then recommended C++ debugging setup

https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/

The first link leads to the folling guide: 


<!DOCTYPE html>
<!-- saved from url=(0071)https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/ -->
<html lang="en" class="wf-oswald-n4-active wf-active"><!--<![endif]--><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

<meta name="viewport" content="width=device-width">
<title>How to program the Raspberry Pi Pico in C on a Mac | smittytone messes with micros</title>
<link rel="profile" href="https://gmpg.org/xfn/11">
<link rel="pingback" href="https://blog.smittytone.net/xmlrpc.php">
<!--[if lt IE 9]>
<script src="https://s0.wp.com/wp-content/themes/pub/twentytwelve/js/html5.js?ver=3.7.0" type="text/javascript"></script>
<![endif]-->
<script type="text/javascript" async="" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/platform.js"></script><script type="text/javascript" async="" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/platform.js"></script><script src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/webfont.js" type="text/javascript" async=""></script><script type="text/javascript">
  WebFontConfig = {"google":{"families":["Oswald:r:latin,latin-ext"]}};
  (function() {
    var wf = document.createElement('script');
    wf.src = 'https://s0.wp.com/wp-content/plugins/custom-fonts/js/webfont.js';
    wf.type = 'text/javascript';
    wf.async = 'true';
    var s = document.getElementsByTagName('script')[0];
    s.parentNode.insertBefore(wf, s);
	})();
</script><style id="jetpack-custom-fonts-css">.wf-active .site-header h1{font-size:33.8px;font-family:"Oswald",sans-serif;font-style:normal;font-weight:400}.wf-active h1, .wf-active h2, .wf-active h3, .wf-active h4, .wf-active h5, .wf-active h6{font-family:"Oswald",sans-serif;font-style:normal;font-weight:400}.wf-active .entry-header .entry-title{font-size:26px;font-weight:400;font-style:normal}.wf-active .comment-content h1, .wf-active .entry-content h1{font-size:27.3px;font-style:normal;font-weight:400}.wf-active .comment-content h2, .wf-active .entry-content h2{font-size:23.4px;font-style:normal;font-weight:400}.wf-active .comment-content h3, .wf-active .entry-content h3{font-size:20.8px;font-style:normal;font-weight:400}.wf-active .comment-content h4, .wf-active .entry-content h4{font-size:18.2px;font-style:normal;font-weight:400}.wf-active .comment-content h5, .wf-active .entry-content h5{font-size:16.9px;font-style:normal;font-weight:400}.wf-active .comment-content h6, .wf-active .entry-content h6{font-size:15.6px;font-style:normal;font-weight:400}.wf-active article.format-image footer h1{font-size:16.9px;font-weight:400;font-style:normal}.wf-active article.format-image footer h2{font-size:14.3px;font-style:normal;font-weight:400}.wf-active article.format-link header{font-size:14.3px;font-weight:400;font-style:normal}.wf-active .comments-title{font-size:20.8px;font-weight:400;font-style:normal}.wf-active .comments-area article header h4{font-size:15.6px;font-weight:400;font-style:normal}.wf-active #respond h3#reply-title{font-size:20.8px;font-style:normal;font-weight:400}.wf-active .entry-header .entry-title{font-size:28.6px;font-style:normal;font-weight:400}</style>
<meta name="robots" content="max-image-preview:large">

<!-- Async WordPress.com Remote Login -->
<script id="wpcom_remote_login_js">
var wpcom_remote_login_extra_auth = '';
function wpcom_remote_login_remove_dom_node_id( element_id ) {
	var dom_node = document.getElementById( element_id );
	if ( dom_node ) { dom_node.parentNode.removeChild( dom_node ); }
}
function wpcom_remote_login_remove_dom_node_classes( class_name ) {
	var dom_nodes = document.querySelectorAll( '.' + class_name );
	for ( var i = 0; i < dom_nodes.length; i++ ) {
		dom_nodes[ i ].parentNode.removeChild( dom_nodes[ i ] );
	}
}
function wpcom_remote_login_final_cleanup() {
	wpcom_remote_login_remove_dom_node_classes( "wpcom_remote_login_msg" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_key" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_validate" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_js" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_request_access_iframe" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_request_access_styles" );
}

// Watch for messages back from the remote login
window.addEventListener( "message", function( e ) {
	if ( e.origin === "https://r-login.wordpress.com" ) {
		var data = {};
		try {
			data = JSON.parse( e.data );
		} catch( e ) {
			wpcom_remote_login_final_cleanup();
			return;
		}

		if ( data.msg === 'LOGIN' ) {
			// Clean up the login check iframe
			wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_key" );

			var id_regex = new RegExp( /^[0-9]+$/ );
			var token_regex = new RegExp( /^.*|.*|.*$/ );
			if (
				token_regex.test( data.token )
				&& id_regex.test( data.wpcomid )
			) {
				// We have everything we need to ask for a login
				var script = document.createElement( "script" );
				script.setAttribute( "id", "wpcom_remote_login_validate" );
				script.src = '/remote-login.php?wpcom_remote_login=validate'
					+ '&wpcomid=' + data.wpcomid
					+ '&token=' + encodeURIComponent( data.token )
					+ '&host=' + window.location.protocol
					+ '//' + window.location.hostname
					+ '&postid=2224'
					+ '&is_singular=1';
				document.body.appendChild( script );
			}

			return;
		}

		// Safari ITP, not logged in, so redirect
		if ( data.msg === 'LOGIN-REDIRECT' ) {
			window.location = 'https://wordpress.com/log-in?redirect_to=' + window.location.href;
			return;
		}

		// Safari ITP, storage access failed, remove the request
		if ( data.msg === 'LOGIN-REMOVE' ) {
			var css_zap = 'html { -webkit-transition: margin-top 1s; transition: margin-top 1s; } /* 9001 */ html { margin-top: 0 !important; } * html body { margin-top: 0 !important; } @media screen and ( max-width: 782px ) { html { margin-top: 0 !important; } * html body { margin-top: 0 !important; } }';
			var style_zap = document.createElement( 'style' );
			style_zap.type = 'text/css';
			style_zap.appendChild( document.createTextNode( css_zap ) );
			document.body.appendChild( style_zap );

			var e = document.getElementById( 'wpcom_request_access_iframe' );
			e.parentNode.removeChild( e );

			document.cookie = 'wordpress_com_login_access=denied; path=/; max-age=31536000';

			return;
		}

		// Safari ITP
		if ( data.msg === 'REQUEST_ACCESS' ) {
			console.log( 'request access: safari' );

			// Check ITP iframe enable/disable knob
			if ( wpcom_remote_login_extra_auth !== 'safari_itp_iframe' ) {
				return;
			}

			// If we are in a "private window" there is no ITP.
			var private_window = false;
			try {
				var opendb = window.openDatabase( null, null, null, null );
			} catch( e ) {
				private_window = true;
			}

			if ( private_window ) {
				console.log( 'private window' );
				return;
			}

			var iframe = document.createElement( 'iframe' );
			iframe.id = 'wpcom_request_access_iframe';
			iframe.setAttribute( 'scrolling', 'no' );
			iframe.setAttribute( 'sandbox', 'allow-storage-access-by-user-activation allow-scripts allow-same-origin allow-top-navigation-by-user-activation' );
			iframe.src = 'https://r-login.wordpress.com/remote-login.php?wpcom_remote_login=request_access&origin=' + encodeURIComponent( data.origin ) + '&wpcomid=' + encodeURIComponent( data.wpcomid );

			var css = 'html { -webkit-transition: margin-top 1s; transition: margin-top 1s; } /* 9001 */ html { margin-top: 46px !important; } * html body { margin-top: 46px !important; } @media screen and ( max-width: 660px ) { html { margin-top: 71px !important; } * html body { margin-top: 71px !important; } #wpcom_request_access_iframe { display: block; height: 71px !important; } } #wpcom_request_access_iframe { border: 0px; height: 46px; position: fixed; top: 0; left: 0; width: 100%; min-width: 100%; z-index: 99999; background: #23282d; } ';

			var style = document.createElement( 'style' );
			style.type = 'text/css';
			style.id = 'wpcom_request_access_styles';
			style.appendChild( document.createTextNode( css ) );
			document.body.appendChild( style );

			document.body.appendChild( iframe );
		}

		if ( data.msg === 'DONE' ) {
			wpcom_remote_login_final_cleanup();
		}
	}
}, false );

// Inject the remote login iframe after the page has had a chance to load
// more critical resources
window.addEventListener( "DOMContentLoaded", function( e ) {
	var iframe = document.createElement( "iframe" );
	iframe.style.display = "none";
	iframe.setAttribute( "scrolling", "no" );
	iframe.setAttribute( "id", "wpcom_remote_login_key" );
	iframe.src = "https://r-login.wordpress.com/remote-login.php"
		+ "?wpcom_remote_login=key"
		+ "&origin=aHR0cHM6Ly9ibG9nLnNtaXR0eXRvbmUubmV0"
		+ "&wpcomid=11065590"
		+ "&time=1635610393";
	document.body.appendChild( iframe );
}, false );
</script>
<link rel="dns-prefetch" href="https://s0.wp.com/">
<link rel="dns-prefetch" href="https://smittytone.wordpress.com/">
<link rel="dns-prefetch" href="https://fonts.googleapis.com/">
<link href="https://fonts.gstatic.com/" crossorigin="" rel="preconnect">
<link rel="alternate" type="application/rss+xml" title="smittytone messes with micros » Feed" href="https://blog.smittytone.net/feed/">
<link rel="alternate" type="application/rss+xml" title="smittytone messes with micros » Comments Feed" href="https://blog.smittytone.net/comments/feed/">
<link rel="alternate" type="application/rss+xml" title="smittytone messes with micros » How to program the Raspberry Pi Pico in C on a Mac Comments Feed" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/feed/">
	<script type="text/javascript">
		/* <![CDATA[ */
		function addLoadEvent(func) {
			var oldonload = window.onload;
			if (typeof window.onload != 'function') {
				window.onload = func;
			} else {
				window.onload = function () {
					oldonload();
					func();
				}
			}
		}
		/* ]]> */
	</script>
			<script type="text/javascript">
			window._wpemojiSettings = {"baseUrl":"https:\/\/s0.wp.com\/wp-content\/mu-plugins\/wpcom-smileys\/twemoji\/2\/72x72\/","ext":".png","svgUrl":"https:\/\/s0.wp.com\/wp-content\/mu-plugins\/wpcom-smileys\/twemoji\/2\/svg\/","svgExt":".svg","source":{"concatemoji":"https:\/\/s0.wp.com\/wp-includes\/js\/wp-emoji-release.min.js?m=1625065786h&ver=5.8.1"}};
			!function(e,a,t){var n,r,o,i=a.createElement("canvas"),p=i.getContext&&i.getContext("2d");function s(e,t){var a=String.fromCharCode;p.clearRect(0,0,i.width,i.height),p.fillText(a.apply(this,e),0,0);e=i.toDataURL();return p.clearRect(0,0,i.width,i.height),p.fillText(a.apply(this,t),0,0),e===i.toDataURL()}function c(e){var t=a.createElement("script");t.src=e,t.defer=t.type="text/javascript",a.getElementsByTagName("head")[0].appendChild(t)}for(o=Array("flag","emoji"),t.supports={everything:!0,everythingExceptFlag:!0},r=0;r<o.length;r++)t.supports[o[r]]=function(e){if(!p||!p.fillText)return!1;switch(p.textBaseline="top",p.font="600 32px Arial",e){case"flag":return s([127987,65039,8205,9895,65039],[127987,65039,8203,9895,65039])?!1:!s([55356,56826,55356,56819],[55356,56826,8203,55356,56819])&&!s([55356,57332,56128,56423,56128,56418,56128,56421,56128,56430,56128,56423,56128,56447],[55356,57332,8203,56128,56423,8203,56128,56418,8203,56128,56421,8203,56128,56430,8203,56128,56423,8203,56128,56447]);case"emoji":return!s([10084,65039,8205,55357,56613],[10084,65039,8203,55357,56613])}return!1}(o[r]),t.supports.everything=t.supports.everything&&t.supports[o[r]],"flag"!==o[r]&&(t.supports.everythingExceptFlag=t.supports.everythingExceptFlag&&t.supports[o[r]]);t.supports.everythingExceptFlag=t.supports.everythingExceptFlag&&!t.supports.flag,t.DOMReady=!1,t.readyCallback=function(){t.DOMReady=!0},t.supports.everything||(n=function(){t.readyCallback()},a.addEventListener?(a.addEventListener("DOMContentLoaded",n,!1),e.addEventListener("load",n,!1)):(e.attachEvent("onload",n),a.attachEvent("onreadystatechange",function(){"complete"===a.readyState&&t.readyCallback()})),(n=t.source||{}).concatemoji?c(n.concatemoji):n.wpemoji&&n.twemoji&&(c(n.twemoji),c(n.wpemoji)))}(window,document,window._wpemojiSettings);
		</script><script src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/wp-emoji-release.min.js" type="text/javascript" defer=""></script>
		<style type="text/css">
img.wp-smiley,
img.emoji {
	display: inline !important;
	border: none !important;
	box-shadow: none !important;
	height: 1em !important;
	width: 1em !important;
	margin: 0 .07em !important;
	vertical-align: -0.1em !important;
	background: none !important;
	padding: 0 !important;
}
</style>
	<link rel="stylesheet" id="all-css-0-1" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(1)" type="text/css" media="all">
<style id="wp-block-library-inline-css">
.has-text-align-justify {
	text-align:justify;
}
</style>
<style id="global-styles-inline-css">
body{--wp--preset--color--black: #000000;--wp--preset--color--cyan-bluish-gray: #abb8c3;--wp--preset--color--white: #ffffff;--wp--preset--color--pale-pink: #f78da7;--wp--preset--color--vivid-red: #cf2e2e;--wp--preset--color--luminous-vivid-orange: #ff6900;--wp--preset--color--luminous-vivid-amber: #fcb900;--wp--preset--color--light-green-cyan: #7bdcb5;--wp--preset--color--vivid-green-cyan: #00d084;--wp--preset--color--pale-cyan-blue: #8ed1fc;--wp--preset--color--vivid-cyan-blue: #0693e3;--wp--preset--color--vivid-purple: #9b51e0;--wp--preset--gradient--vivid-cyan-blue-to-vivid-purple: linear-gradient(135deg,rgba(6,147,227,1) 0%,rgb(155,81,224) 100%);--wp--preset--gradient--light-green-cyan-to-vivid-green-cyan: linear-gradient(135deg,rgb(122,220,180) 0%,rgb(0,208,130) 100%);--wp--preset--gradient--luminous-vivid-amber-to-luminous-vivid-orange: linear-gradient(135deg,rgba(252,185,0,1) 0%,rgba(255,105,0,1) 100%);--wp--preset--gradient--luminous-vivid-orange-to-vivid-red: linear-gradient(135deg,rgba(255,105,0,1) 0%,rgb(207,46,46) 100%);--wp--preset--gradient--very-light-gray-to-cyan-bluish-gray: linear-gradient(135deg,rgb(238,238,238) 0%,rgb(169,184,195) 100%);--wp--preset--gradient--cool-to-warm-spectrum: linear-gradient(135deg,rgb(74,234,220) 0%,rgb(151,120,209) 20%,rgb(207,42,186) 40%,rgb(238,44,130) 60%,rgb(251,105,98) 80%,rgb(254,248,76) 100%);--wp--preset--gradient--blush-light-purple: linear-gradient(135deg,rgb(255,206,236) 0%,rgb(152,150,240) 100%);--wp--preset--gradient--blush-bordeaux: linear-gradient(135deg,rgb(254,205,165) 0%,rgb(254,45,45) 50%,rgb(107,0,62) 100%);--wp--preset--gradient--luminous-dusk: linear-gradient(135deg,rgb(255,203,112) 0%,rgb(199,81,192) 50%,rgb(65,88,208) 100%);--wp--preset--gradient--pale-ocean: linear-gradient(135deg,rgb(255,245,203) 0%,rgb(182,227,212) 50%,rgb(51,167,181) 100%);--wp--preset--gradient--electric-grass: linear-gradient(135deg,rgb(202,248,128) 0%,rgb(113,206,126) 100%);--wp--preset--gradient--midnight: linear-gradient(135deg,rgb(2,3,129) 0%,rgb(40,116,252) 100%);--wp--preset--duotone--dark-grayscale: url('#wp-duotone-dark-grayscale');--wp--preset--duotone--grayscale: url('#wp-duotone-grayscale');--wp--preset--duotone--purple-yellow: url('#wp-duotone-purple-yellow');--wp--preset--duotone--blue-red: url('#wp-duotone-blue-red');--wp--preset--duotone--midnight: url('#wp-duotone-midnight');--wp--preset--duotone--magenta-yellow: url('#wp-duotone-magenta-yellow');--wp--preset--duotone--purple-green: url('#wp-duotone-purple-green');--wp--preset--duotone--blue-orange: url('#wp-duotone-blue-orange');--wp--preset--font-size--small: 13px;--wp--preset--font-size--normal: 16px;--wp--preset--font-size--medium: 20px;--wp--preset--font-size--large: 36px;--wp--preset--font-size--huge: 42px;}.has-black-color{color: var(--wp--preset--color--black) !important;}.has-cyan-bluish-gray-color{color: var(--wp--preset--color--cyan-bluish-gray) !important;}.has-white-color{color: var(--wp--preset--color--white) !important;}.has-pale-pink-color{color: var(--wp--preset--color--pale-pink) !important;}.has-vivid-red-color{color: var(--wp--preset--color--vivid-red) !important;}.has-luminous-vivid-orange-color{color: var(--wp--preset--color--luminous-vivid-orange) !important;}.has-luminous-vivid-amber-color{color: var(--wp--preset--color--luminous-vivid-amber) !important;}.has-light-green-cyan-color{color: var(--wp--preset--color--light-green-cyan) !important;}.has-vivid-green-cyan-color{color: var(--wp--preset--color--vivid-green-cyan) !important;}.has-pale-cyan-blue-color{color: var(--wp--preset--color--pale-cyan-blue) !important;}.has-vivid-cyan-blue-color{color: var(--wp--preset--color--vivid-cyan-blue) !important;}.has-vivid-purple-color{color: var(--wp--preset--color--vivid-purple) !important;}.has-black-background-color{background-color: var(--wp--preset--color--black) !important;}.has-cyan-bluish-gray-background-color{background-color: var(--wp--preset--color--cyan-bluish-gray) !important;}.has-white-background-color{background-color: var(--wp--preset--color--white) !important;}.has-pale-pink-background-color{background-color: var(--wp--preset--color--pale-pink) !important;}.has-vivid-red-background-color{background-color: var(--wp--preset--color--vivid-red) !important;}.has-luminous-vivid-orange-background-color{background-color: var(--wp--preset--color--luminous-vivid-orange) !important;}.has-luminous-vivid-amber-background-color{background-color: var(--wp--preset--color--luminous-vivid-amber) !important;}.has-light-green-cyan-background-color{background-color: var(--wp--preset--color--light-green-cyan) !important;}.has-vivid-green-cyan-background-color{background-color: var(--wp--preset--color--vivid-green-cyan) !important;}.has-pale-cyan-blue-background-color{background-color: var(--wp--preset--color--pale-cyan-blue) !important;}.has-vivid-cyan-blue-background-color{background-color: var(--wp--preset--color--vivid-cyan-blue) !important;}.has-vivid-purple-background-color{background-color: var(--wp--preset--color--vivid-purple) !important;}.has-black-border-color{border-color: var(--wp--preset--color--black) !important;}.has-cyan-bluish-gray-border-color{border-color: var(--wp--preset--color--cyan-bluish-gray) !important;}.has-white-border-color{border-color: var(--wp--preset--color--white) !important;}.has-pale-pink-border-color{border-color: var(--wp--preset--color--pale-pink) !important;}.has-vivid-red-border-color{border-color: var(--wp--preset--color--vivid-red) !important;}.has-luminous-vivid-orange-border-color{border-color: var(--wp--preset--color--luminous-vivid-orange) !important;}.has-luminous-vivid-amber-border-color{border-color: var(--wp--preset--color--luminous-vivid-amber) !important;}.has-light-green-cyan-border-color{border-color: var(--wp--preset--color--light-green-cyan) !important;}.has-vivid-green-cyan-border-color{border-color: var(--wp--preset--color--vivid-green-cyan) !important;}.has-pale-cyan-blue-border-color{border-color: var(--wp--preset--color--pale-cyan-blue) !important;}.has-vivid-cyan-blue-border-color{border-color: var(--wp--preset--color--vivid-cyan-blue) !important;}.has-vivid-purple-border-color{border-color: var(--wp--preset--color--vivid-purple) !important;}.has-vivid-cyan-blue-to-vivid-purple-gradient-background{background: var(--wp--preset--gradient--vivid-cyan-blue-to-vivid-purple) !important;}.has-light-green-cyan-to-vivid-green-cyan-gradient-background{background: var(--wp--preset--gradient--light-green-cyan-to-vivid-green-cyan) !important;}.has-luminous-vivid-amber-to-luminous-vivid-orange-gradient-background{background: var(--wp--preset--gradient--luminous-vivid-amber-to-luminous-vivid-orange) !important;}.has-luminous-vivid-orange-to-vivid-red-gradient-background{background: var(--wp--preset--gradient--luminous-vivid-orange-to-vivid-red) !important;}.has-very-light-gray-to-cyan-bluish-gray-gradient-background{background: var(--wp--preset--gradient--very-light-gray-to-cyan-bluish-gray) !important;}.has-cool-to-warm-spectrum-gradient-background{background: var(--wp--preset--gradient--cool-to-warm-spectrum) !important;}.has-blush-light-purple-gradient-background{background: var(--wp--preset--gradient--blush-light-purple) !important;}.has-blush-bordeaux-gradient-background{background: var(--wp--preset--gradient--blush-bordeaux) !important;}.has-luminous-dusk-gradient-background{background: var(--wp--preset--gradient--luminous-dusk) !important;}.has-pale-ocean-gradient-background{background: var(--wp--preset--gradient--pale-ocean) !important;}.has-electric-grass-gradient-background{background: var(--wp--preset--gradient--electric-grass) !important;}.has-midnight-gradient-background{background: var(--wp--preset--gradient--midnight) !important;}.has-small-font-size{font-size: var(--wp--preset--font-size--small) !important;}.has-normal-font-size{font-size: var(--wp--preset--font-size--normal) !important;}.has-medium-font-size{font-size: var(--wp--preset--font-size--medium) !important;}.has-large-font-size{font-size: var(--wp--preset--font-size--large) !important;}.has-huge-font-size{font-size: var(--wp--preset--font-size--huge) !important;}
</style>
<link crossorigin="anonymous" rel="stylesheet" id="twentytwelve-fonts-css" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/css" media="all">
<link rel="stylesheet" id="all-css-4-1" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(2)" type="text/css" media="all">
<!--[if lt IE 9]>
<link rel='stylesheet' id='twentytwelve-ie-css'  href='https://s0.wp.com/wp-content/themes/pub/twentytwelve/css/ie.css?m=1423935238h&#038;ver=20150214' media='all' />
<![endif]-->
<link rel="stylesheet" id="all-css-6-1" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(3)" type="text/css" media="all">
<style id="jetpack-global-styles-frontend-style-inline-css">
:root { --font-headings: unset; --font-base: unset; --font-headings-default: -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Oxygen-Sans,Ubuntu,Cantarell,"Helvetica Neue",sans-serif; --font-base-default: -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Oxygen-Sans,Ubuntu,Cantarell,"Helvetica Neue",sans-serif;}
</style>
<link rel="stylesheet" id="all-css-8-1" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(4)" type="text/css" media="all">
<script id="jetpack_related-posts-js-extra">
var related_posts_js_options = {"post_heading":"h4"};
</script>
<script id="wpcom-actionbar-placeholder-js-extra">
var actionbardata = {"siteID":"11065590","siteName":"smittytone messes with micros","siteURL":"https:\/\/blog.smittytone.net","siteHost":"blog.smittytone.net","icon":"<img alt='' src='https:\/\/smittytone.files.wordpress.com\/2020\/07\/cropped-rassilonblackwhite.png?w=50' class='avatar avatar-50' height='50' width='50' \/>","canManageOptions":"","canCustomizeSite":"","isFollowing":"","themeSlug":"pub\/twentytwelve","signupURL":"https:\/\/wordpress.com\/start\/","loginURL":"https:\/\/wordpress.com\/log-in?redirect_to=https%3A%2F%2Fr-login.wordpress.com%2Fremote-login.php%3Faction%3Dlink%26back%3Dhttps%253A%252F%252Fblog.smittytone.net%252F2021%252F02%252F02%252Fprogram-raspberry-pi-pico-c-mac%252F","themeURL":"https:\/\/wordpress.com\/theme\/twentytwelve\/","xhrURL":"https:\/\/blog.smittytone.net\/wp-admin\/admin-ajax.php","nonce":"8ec0ac2dfd","isSingular":"1","isFolded":"","isLoggedIn":"","isMobile":"","subscribeNonce":"<input type=\"hidden\" id=\"_wpnonce\" name=\"_wpnonce\" value=\"4723af681c\" \/>","referer":"https:\/\/blog.smittytone.net\/2021\/02\/02\/program-raspberry-pi-pico-c-mac\/","canFollow":"1","feedID":"115848462","statusMessage":"","subsEmailDefault":"instantly","customizeLink":"https:\/\/smittytone.wordpress.com\/wp-admin\/customize.php?url=https%3A%2F%2Fsmittytone.wordpress.com%2F2021%2F02%2F02%2Fprogram-raspberry-pi-pico-c-mac%2F","postID":"2224","shortlink":"https:\/\/wp.me\/pKqFg-zS","canEditPost":"","editLink":"https:\/\/wordpress.com\/post\/blog.smittytone.net\/2224","statsLink":"https:\/\/wordpress.com\/stats\/post\/2224\/blog.smittytone.net","i18n":{"view":"View site","follow":"Follow","following":"Following","edit":"Edit","login":"Log in","signup":"Sign up","customize":"Customize","report":"Report this content","themeInfo":"Get theme: Twenty Twelve","shortlink":"Copy shortlink","copied":"Copied","followedText":"New posts from this site will now appear in your <a href=\"https:\/\/wordpress.com\/read\">Reader<\/a>","foldBar":"Collapse this bar","unfoldBar":"Expand this bar","editSubs":"Manage subscriptions","viewReader":"View site in Reader","viewReadPost":"View post in Reader","subscribe":"Sign me up","enterEmail":"Enter your email address","followers":"Join 138 other followers","alreadyUser":"Already have a WordPress.com account? <a href=\"https:\/\/wordpress.com\/log-in?redirect_to=https%3A%2F%2Fr-login.wordpress.com%2Fremote-login.php%3Faction%3Dlink%26back%3Dhttps%253A%252F%252Fblog.smittytone.net%252F2021%252F02%252F02%252Fprogram-raspberry-pi-pico-c-mac%252F\">Log in now.<\/a>","stats":"Stats","notifyNewPosts":"Notify me of new posts","notifyNewPostsDetails":"Receive web and mobile notifications for new posts from this site.","emailNewPosts":"Email me new posts","emailNewPostsDetails":"You can customize your notification settings further <a href=\"https:\/\/wordpress.com\/following\/manage?s=blog.smittytone.net\">here<\/a>.","emailNewComments":"Email me new comments","instantly":"Instantly","daily":"Daily","weekly":"Weekly"}};
</script>
<script crossorigin="anonymous" type="text/javascript" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(5)"></script>
<script type="text/javascript">
	window.addEventListener( 'DOMContentLoaded', function() {
		rltInitialize( {"token":null,"iframeOrigins":["https:\/\/widgets.wp.com"]} );
	} );
</script>
<link rel="EditURI" type="application/rsd+xml" title="RSD" href="https://smittytone.wordpress.com/xmlrpc.php?rsd">
<link rel="wlwmanifest" type="application/wlwmanifest+xml" href="https://s0.wp.com/wp-includes/wlwmanifest.xml"> 
<meta name="generator" content="WordPress.com">
<link rel="canonical" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/">
<link rel="shortlink" href="https://wp.me/pKqFg-zS">
<link rel="alternate" type="application/json+oembed" href="https://public-api.wordpress.com/oembed/?format=json&amp;url=https%3A%2F%2Fblog.smittytone.net%2F2021%2F02%2F02%2Fprogram-raspberry-pi-pico-c-mac%2F&amp;for=wpcom-auto-discovery"><link rel="alternate" type="application/xml+oembed" href="https://public-api.wordpress.com/oembed/?format=xml&amp;url=https%3A%2F%2Fblog.smittytone.net%2F2021%2F02%2F02%2Fprogram-raspberry-pi-pico-c-mac%2F&amp;for=wpcom-auto-discovery">
<!-- Jetpack Open Graph Tags -->
<meta property="og:type" content="article">
<meta property="og:title" content="How to program the Raspberry Pi Pico in C on a Mac">
<meta property="og:url" content="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/">
<meta property="og:description" content="Last week I tried the Raspberry Pi Pico with MicroPython. The Raspberry Pi Foundation would be sufficiently commended for providing only this level of programming support. MicroPython leverages the…">
<meta property="article:published_time" content="2021-02-02T09:49:36+00:00">
<meta property="article:modified_time" content="2021-09-03T06:34:57+00:00">
<meta property="og:site_name" content="smittytone messes with micros">
<meta property="og:image" content="https://smittytone.files.wordpress.com/2021/02/pico.jpg">
<meta property="og:image:width" content="1120">
<meta property="og:image:height" content="514">
<meta property="og:locale" content="en_US">
<meta name="twitter:creator" content="@TechTonicBlog">
<meta name="twitter:site" content="@TechTonicBlog">
<meta name="twitter:text:title" content="How to program the Raspberry Pi Pico in C on a Mac">
<meta name="twitter:image" content="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=640">
<meta name="twitter:card" content="summary_large_image">
<meta property="article:publisher" content="https://www.facebook.com/WordPresscom">

<!-- End Jetpack Open Graph Tags -->
<link rel="openid.server" href="https://blog.smittytone.net/?openidserver=1">
<link rel="openid.delegate" href="https://blog.smittytone.net/">
<link rel="search" type="application/opensearchdescription+xml" href="https://blog.smittytone.net/osd.xml" title="smittytone messes with micros">
<link rel="search" type="application/opensearchdescription+xml" href="https://s1.wp.com/opensearch.xml" title="WordPress.com">
<meta name="theme-color" content="#e6e6e6">
<meta name="application-name" content="smittytone messes with micros"><meta name="msapplication-window" content="width=device-width;height=device-height"><meta name="msapplication-tooltip" content="BULLETINS FROM THE TECHNOLOGY FRONT LINE — AND OCCASIONALLY BEHIND IT"><meta name="msapplication-task" content="name=Subscribe;action-uri=https://blog.smittytone.net/feed/;icon-uri=https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=16"><meta name="msapplication-task" content="name=Sign up for a free blog;action-uri=http://wordpress.com/signup/;icon-uri=https://s0.wp.com/i/favicon.ico"><meta name="msapplication-task" content="name=WordPress.com Support;action-uri=http://support.wordpress.com/;icon-uri=https://s0.wp.com/i/favicon.ico"><meta name="msapplication-task" content="name=WordPress.com Forums;action-uri=http://forums.wordpress.com/;icon-uri=https://s0.wp.com/i/favicon.ico"><meta name="description" content="Last week I tried the Raspberry Pi Pico with MicroPython. The Raspberry Pi Foundation would be sufficiently commended for providing only this level of programming support. MicroPython leverages the Python skills of the many Raspberry Pi users out there and is accessible to plenty of others too. But the Foundation has also provided a C/C++…">
	<style type="text/css" id="twentytwelve-header-css">
			.site-title,
		.site-description {
			position: absolute;
			clip: rect(1px 1px 1px 1px); /* IE7 */
			clip: rect(1px, 1px, 1px, 1px);
		}
		</style>
	<link rel="amphtml" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/amp/"><link rel="icon" href="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=32" sizes="32x32">
<link rel="icon" href="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=192" sizes="192x192">
<link rel="apple-touch-icon" href="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=180">
<meta name="msapplication-TileImage" content="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=270">
<link rel="stylesheet" type="text/css" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/shCore.css"><link rel="stylesheet" type="text/css" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/shThemeDefault.css"><script charset="utf-8" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/rate.php"></script><link rel="stylesheet" type="text/css" id="gravatar-card-css" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/hovercard.min.css"><link rel="stylesheet" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/css(1)" media="all"><link rel="stylesheet" type="text/css" id="gravatar-card-services-css" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/services.min.css"><style type="text/css" id="pd_popup_holder_style_1209223_post_2224">#pd_popup_holder_1209223_post_2224 { position:absolute; display:none; width:350px; height:auto; top:0px; left:0px; z-index:10000; border:solid 1px #CCC; background-color:white; padding:0px 15px;font-family:Arial,Sans;box-shadow: -10px 10px 20px rgba(0, 0, 0, .5);-webkit-box-shadow: 0px 0px 6px rgba(0, 0, 0, .25);-moz-box-shadow: 0px 0px 6px rgba(0, 0, 0, .25); }</style><link href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/actionbar.css" type="text/css" rel="stylesheet"></head>

<body class="post-template-default single single-post postid-2224 single-format-standard wp-custom-logo wp-embed-responsive customizer-styles-applied custom-font-enabled single-author highlander-enabled highlander-light">
<div id="page" class="hfeed site">
	<header id="masthead" class="site-header" role="banner">
				<hgroup>
			<h1 class="site-title"><a href="https://blog.smittytone.net/" title="smittytone messes with micros" rel="home">smittytone messes with micros</a></h1>
			<h2 class="site-description">BULLETINS FROM THE TECHNOLOGY FRONT LINE —&nbsp;AND OCCASIONALLY BEHIND IT</h2>
		</hgroup>

		<nav id="site-navigation" class="main-navigation" role="navigation">
			<button class="menu-toggle">Menu</button>
			<a class="assistive-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/#content" title="Skip to content">Skip to content</a>
			<div class="menu-main-menu-container"><ul id="menu-main-menu" class="nav-menu"><li id="menu-item-612" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-home menu-item-has-children menu-item-612"><a href="https://blog.smittytone.net/">Home</a>
<ul class="sub-menu">
	<li id="menu-item-613" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-613"><a href="https://blog.smittytone.net/about/">About this Blog…</a></li>
</ul>
</li>
<li id="menu-item-1314" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-has-children menu-item-1314"><a href="https://blog.smittytone.net/category/mac/">Mac</a>
<ul class="sub-menu">
	<li id="menu-item-1543" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-1543"><a href="https://blog.smittytone.net/category/how-to-mac/">How To (Mac)</a></li>
	<li id="menu-item-1315" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-1315"><a href="https://blog.smittytone.net/category/programming/">Programming</a></li>
</ul>
</li>
<li id="menu-item-614" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-has-children menu-item-614"><a href="https://blog.smittytone.net/category/raspberry-pi/">Raspberry Pi</a>
<ul class="sub-menu">
	<li id="menu-item-1484" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-1484"><a href="https://blog.smittytone.net/pi-knowledgebase/">Raspberry Pi Knowledgebase</a></li>
	<li id="menu-item-1542" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-1542"><a href="https://blog.smittytone.net/category/how-to-pi/">How To (Pi)</a></li>
	<li id="menu-item-934" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-934"><a href="https://blog.smittytone.net/category/hacks/">Hacks</a></li>
</ul>
</li>
<li id="menu-item-2996" class="menu-item menu-item-type-taxonomy menu-item-object-post_tag menu-item-2996"><a href="https://blog.smittytone.net/tag/pico/">Pico</a></li>
<li id="menu-item-663" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-663"><a href="https://blog.smittytone.net/category/retro/">Retro</a></li>
</ul></div>		</nav><!-- #site-navigation -->

						<a href="https://blog.smittytone.net/"><img src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/slice.png" class="header-image" width="1924" height="200" alt="" scale="0"></a>
			</header><!-- #masthead -->

	<div id="main" class="wrapper">
	<div id="primary" class="site-content">
		<div id="content" role="main">

			
				
	<article id="post-2224" class="post-2224 post type-post status-publish format-standard hentry category-how-to-mac category-how-to-pi category-raspberry-pi tag-c-2 tag-c-c tag-mac tag-macos tag-osx tag-pico tag-raspberry-pi">
				<header class="entry-header">
			
						<h1 class="entry-title">How to program the Raspberry Pi Pico in C on a&nbsp;Mac</h1>
								</header><!-- .entry-header -->

				<div class="entry-content">
			
<p>Last week I tried the <a href="https://blog.smittytone.net/2021/01/23/first-look-the-raspberry-pi-pico-on-mac/">Raspberry Pi Pico with MicroPython</a>. The Raspberry Pi Foundation would be sufficiently commended for providing only this level of programming support. <a rel="noreferrer noopener" href="https://micropython.org/" target="_blank">MicroPython</a> leverages the Python skills of the many Raspberry Pi users out there and is accessible to plenty of others too. But the Foundation has also provided a C/C++ SDK, and this opens the Pico up to serious embedded-system developers too.</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico.jpg"><img data-attachment-id="2238" data-permalink="https://blog.smittytone.net/pico/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg" data-orig-size="1120,514" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="pico" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=625" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/pico.jpg" alt="The Raspberry Pi Pico" class="wp-image-2238" srcset="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=1024 1024w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico.jpg 1120w" sizes="(max-width: 1024px) 100vw, 1024px"></a></figure></div>



<span id="more-2224"></span>



<p>Programming in C or C++ brings you so much closer to the bare metal than an interpreted language like Python can. With the SDK, you’re not totally there: compiling a simple <code>Hello, World</code> program, for example, generates a very small binary but it’s still a little larger than you might expect. There is a lot of ancillary code added by the SDK in there too. That’s inevitable: this way you don’t have to worry about the complexities of installing your code into the correct part of the target chip’s memory map and can instead focus on your application code.</p>



<p>For those of us who aren’t experienced embedded developers, the SDK is set up to generate <code>.uf2</code> files so that you can just mount the Pico’s internal storage on your computer and drag the binary across, just as you would with MicroPython source. When you do, the Pico reboots, installs the compiled code and runs it.</p>



<p>This approach is convenient for embedded newbies, but it’s a faff having to re-mount your Pico every time you update your code — not to mention tough on the USB connector. The Pico supports a much better alternative: <a rel="noreferrer noopener" href="https://en.wikipedia.org/wiki/Serial_Wire_Debug?wprov=srpw1_1" target="_blank">Serial Wire Debug</a> (SWD), accessed through the three pins marked <strong>DEBUG</strong> on the far edge from the USB connector. </p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg"><img data-attachment-id="2240" data-permalink="https://blog.smittytone.net/pico-debug/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg" data-orig-size="1120,514" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="pico-debug" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=625" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/pico-debug.jpg" alt="The Raspberry Pi Pico SWD (serial wire debug) header" class="wp-image-2240" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=1024 1024w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg 1120w" sizes="(max-width: 1024px) 100vw, 1024px"></a><figcaption>The Pico’s SWD header</figcaption></figure></div>



<p>These SWD pins can be used for transferring code to the Pico without all that tedious plugging and unplugging of USB cables. More to the point, it is used to enable on-chip debugging so that you can see how your code is operating on the machine and do useful things like set breakpoints so you can pause the program to check the value of variables and such. This is much better way of debugging development code, but working with SWD on a Mac is not straightforward, so I’ll be covering it separately.</p>



<h2 class="has-text-color" style="color:#4e65ae;">Installing the Tools</h2>



<p>First, though this is how you set up your Pico toolchain on a Mac. The Foundation documents this, but different parts of the setup are covered in different places, so here is my combined, tested sequence. As an example, I’ll use the directory <code>~/git</code> as the base installation location and the project name <code>PicoTest</code>, but you can use whatever paths and names you prefer, of course.</p>



<p></p>



<ol><li>Install the SDK:<ol><li>In Terminal, go to your projects directory, eg. <code>~/git</code></li><li>Run <code>git clone -b master --recurse-submodules</code> <code>https://github.com/raspberrypi/pico-sdk.git</code></li><li>Edit your <code>.bash_profile</code> or <code>.zshrc</code> and add: <br><code>export PICO_SDK_PATH="$HOME/git/pico-sdk"</code></li></ol></li><li>Install the toolchain:<ol><li><code>brew install cmake</code></li><li><code>brew tap ArmMbed/homebrew-formulae</code></li><li><code>brew install arm-none-eabi-gcc</code></li></ol></li><li>Configure the IDE:<ol><li>Run —&nbsp;or <a rel="noreferrer noopener" href="https://code.visualstudio.com/download" target="_blank">install and then run</a> —&nbsp;Microsoft Visual Studio Code.</li><li>Click on the Extensions icon.</li><li>Enter <code>CMake Tools</code> in the search field.</li><li>Locate CMake Tools by Microsoft and click <strong>Install</strong>.</li></ol></li><li>Set up a project:<ol><li><code>mkdir PicoTest</code></li><li><code>cd PicoTest</code></li><li><code>cp ../pico-sdk/external/pico_sdk_import.cmake .</code></li><li>Create <code>CMakeLists.txt</code> —&nbsp;see listing below.</li><li><code>touch source.h</code></li><li><code>echo '#include "source.h"' &gt; source.c</code></li></ol></li><li>From within Visual Studio Code, open the folder <code>PicoTest</code>.</li><li>When CMakeTools asks you if to configure project, say yes.</li><li>When asked to select a kit, select <strong>GCC for arm-none-eabi x.y.z</strong>.</li></ol>



<p>The <code>CMakeLists.tx</code>t file mentioned in step 4.4 is the configuration file for <em>CMake</em>, which organises the compiling and linking of the code. Here is some boilerplate for the project’s <code>CMakeLists.txt</code> file:</p>


<div class="wp-block-syntaxhighlighter-code "><div><div id="highlighter_81137" class="syntaxhighlighter nogutter  bash"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="bash comments"># What CMake to start at</code></div><div class="line number2 index1 alt1"><code class="bash plain">cmake_minimum_required(VERSION 3.12)</code></div><div class="line number3 index2 alt2">&nbsp;</div><div class="line number4 index3 alt1"><code class="bash comments"># Include the subsidiary .cmake file to get the SDK</code></div><div class="line number5 index4 alt2"><code class="bash plain">include(pico_sdk_import.cmake)</code></div><div class="line number6 index5 alt1">&nbsp;</div><div class="line number7 index6 alt2"><code class="bash comments"># Set the name and version of the project</code></div><div class="line number8 index7 alt1"><code class="bash plain">project(PicoTest VERSION 1.0.0)</code></div><div class="line number9 index8 alt2">&nbsp;</div><div class="line number10 index9 alt1"><code class="bash comments"># Link the Project to a source file (step 4.6)</code></div><div class="line number11 index10 alt2"><code class="bash plain">add_executable(PicoTest </code><code class="bash functions">source</code><code class="bash plain">.c)</code></div><div class="line number12 index11 alt1">&nbsp;</div><div class="line number13 index12 alt2"><code class="bash comments"># Link the Project to an extra library (pico_stdlib)</code></div><div class="line number14 index13 alt1"><code class="bash plain">target_link_libraries(PicoTest pico_stdlib)</code></div><div class="line number15 index14 alt2">&nbsp;</div><div class="line number16 index15 alt1"><code class="bash comments"># Initalise the SDK</code></div><div class="line number17 index16 alt2"><code class="bash plain">pico_sdk_init()</code></div><div class="line number18 index17 alt1">&nbsp;</div><div class="line number19 index18 alt2"><code class="bash comments"># Enable USB, UART output</code></div><div class="line number20 index19 alt1"><code class="bash plain">pico_enable_stdio_usb(PicoTest 1)</code></div><div class="line number21 index20 alt2"><code class="bash plain">pico_enable_stdio_uart(PicoTest 1)</code></div><div class="line number22 index21 alt1">&nbsp;</div><div class="line number23 index22 alt2"><code class="bash comments"># Enable extra outputs (SWD?)</code></div><div class="line number24 index23 alt1"><code class="bash plain">pico_add_extra_outputs(PicoTest)</code></div></div></td></tr></tbody></table></div></div></div>


<p>Your <code>source.h</code> file will grow as you add function prototypes, <code>#define</code> statements and so on, but you’ll need start with some basic <code>#include</code> statements:</p>


<div class="wp-block-syntaxhighlighter-code "><div><div id="highlighter_139779" class="syntaxhighlighter  cpp"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="cpp preprocessor">#include &lt;stdio.h&gt;</code></div><div class="line number2 index1 alt1"><code class="cpp preprocessor">#include "pico/stdlib.h"</code></div></div></td></tr></tbody></table></div></div></div>


<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-c-project.png"><img data-attachment-id="2235" data-permalink="https://blog.smittytone.net/pico-c-project/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-c-project.png" data-orig-size="1202,494" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-c-project" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-c-project.png?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-c-project.png?w=625" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/pico-c-project.png" alt="A basic Pi Pico C project file set" class="wp-image-2235" srcset="https://smittytone.files.wordpress.com/2021/02/pico-c-project.png?w=1024 1024w, https://smittytone.files.wordpress.com/2021/02/pico-c-project.png?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico-c-project.png?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico-c-project.png?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico-c-project.png 1202w" sizes="(max-width: 1024px) 100vw, 1024px"></a><figcaption><em>A basic Pi Pico C project file set</em></figcaption></figure></div>



<p>When you go beyond the basic <code>Hello, World</code> examples in the manual, you’ll start using other Pico libraries. Make sure you add them to the <code>CMakeLists.txt</code> file’s <code>target_link_libraries()</code> call. You can tell when you have forgotten to do this: compiling will fail with an error at one of your <code>#include</code> lines.</p>



<p>There’s not a 1:1 correspondence between the library name and the relevant <code>#include</code>. For example, to use I²C, you add <code>#include "hardware/i2c.h"</code> to your source, but the name you add to <code>target_link_libraries()</code> is <code>hardware_i2c</code>.</p>



<p>The library names are listed in <a href="https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf" target="_blank" rel="noreferrer noopener">the Pico C/C++ SDK documentation</a>.</p>



<h2 class="has-text-color" style="color:#4e65ae;">Projects</h2>



<p>Once the toolchain is in place, setting up a project — step 4 —&nbsp;is straightforward. So I just turned it into a shell script, which <a href="https://github.com/smittytone/pi-pico/tree/main/makepico">you can find in my pi-pico repository on GitHub</a>. Just run it in the Terminal as follows with a path to the project folder you’d like to create — <em>makepico</em> takes the project name from the last item on the path:</p>



<pre class="wp-block-preformatted">makepico ~/my_pico_projects/killer_iot_device</pre>



<p>It will create the folder, add stub source files (<code>.h</code> and <code>.c</code>) and configure a <code>CMakeLists.txt</code> for you.</p>



<p>With the project in view in Visual Studio Code, you can write some code in your <code>.c</code> file and then you just click <strong>Build</strong> in the status bar at the bottom to compile it. Assuming that completes without error, you’ll have a build directory under <code>~/git/PicoTest/</code> and inside that a <code>PicoTest.uf2</code> that you can drag to the Pico’s mounted storage. On a raw board, this will mount automatically. If you have already copied a file over, you’ll need to hold down the <strong>BOOTSEL</strong> button while you connect the Pico to a Mac USB port, and then release it.</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg"><img data-attachment-id="2241" data-permalink="https://blog.smittytone.net/pico-bootsel/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg" data-orig-size="1120,514" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="pico-bootsel" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg?w=625" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/pico-bootsel.jpg" alt="The Raspberry Pi Pico&#39;s boot select button" class="wp-image-2241" srcset="https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg?w=1024 1024w, https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico-bootsel.jpg 1120w" sizes="(max-width: 1024px) 100vw, 1024px"></a><figcaption>The Pico’s BOOTSEL-ect button — press and insert a USB cable to mount its Flash storage</figcaption></figure></div>



<h2 class="has-text-color" style="color:#4e65ae;">Examples</h2>



<p>The Foundation has a wealth of <a rel="noreferrer noopener" href="https://github.com/raspberrypi/pico-examples" target="_blank">Pico C programming examples over at GitHub</a>. They cover all of the Pico’s hardware features, including its Programmable IO (PIO) system for assembly-style DIY bus programming, so there’s plenty there to get you started, whatever your project. Rather the download them all, as the official documentation guides you to do, you may prefer just to view the code as you need to. My setup sequence assumes that’s what you’ll do. </p>



<h2 class="has-text-color" style="color:#4e65ae;">Next Time…</h2>



<p>I’ll show you how to make use of the Pico’s handy SWD header for software loading and on-chip debugging.</p>



<h2 class="has-text-color" style="color:#4e65ae;">More on the Raspberry Pi Pico</h2>



<ul><li><a href="https://blog.smittytone.net/2021/08/30/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-two/">How to build a cellular IoT device with the Raspberry Pi Pico — part two, the&nbsp;code</a></li><li><a href="https://blog.smittytone.net/2021/08/20/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-one/">How to build a cellular IoT device with the Pico — part one, the&nbsp;hardware</a></li><li><a href="https://blog.smittytone.net/2021/07/24/how-to-pop-up-a-picoprobe-from-the-adafruit-qy-py-rp2040/">How to pop up a Picoprobe from the Adafruit QT Py&nbsp;RP2040</a></li><li><a href="https://blog.smittytone.net/2021/07/02/raspberry-pi-pico-proxies-pimoroni-tiny-2040-adafruit-qt-py-rp2040/">Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py&nbsp;RP2040</a></li><li><a href="https://blog.smittytone.net/2021/04/30/c-plus-plus-on-the-raspberry-pi-pico/">Introducing C++ programming on the Raspberry Pi Pico</a></li><li><a href="https://blog.smittytone.net/2021/03/26/3d-arcade-action-courtesy-of-raspberry-pi-pico/">Enjoy some old school 3D arcade action — courtesy of the Raspberry Pi&nbsp;Pico</a></li><li><a href="https://blog.smittytone.net/2021/02/20/hunt-the-wumpus-raspberry-pi-pico-style/">Play Hunt the Wumpus, Raspberry Pi Pico&nbsp;style</a>&nbsp;</li><li><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">How to Debug a Raspberry Pi Pico with a Mac, SWD and… another Pico</a></li><li><a href="https://blog.smittytone.net/2021/01/23/first-look-the-raspberry-pi-pico-on-mac/">A First Look at a MicroPython Marvel: The Raspberry Pi Pico</a></li></ul>



<p></p>
<div id="jp-post-flair" class="sharedaddy sd-rating-enabled sd-like-enabled sd-sharing-enabled"><div class="sd-block sd-rating"><h3 class="sd-title">Rate this:</h3><div class="cs-rating pd-rating" id="pd_rating_holder_1209223_post_2224" style="display: inline-block;"><div class="rating-icons" id="pd_rate_1209223_post_2224" style="float:left;"><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2224.rebuild();" onclick="PDRTJS_1209223_post_2224.rate(1);" onmouseover="PDRTJS_1209223_post_2224.hover(1);" id="PDRTJS_1209223_post_2224_stars_1" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2224.rebuild();" onclick="PDRTJS_1209223_post_2224.rate(2);" onmouseover="PDRTJS_1209223_post_2224.hover(2);" id="PDRTJS_1209223_post_2224_stars_2" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2224.rebuild();" onclick="PDRTJS_1209223_post_2224.rate(3);" onmouseover="PDRTJS_1209223_post_2224.hover(3);" id="PDRTJS_1209223_post_2224_stars_3" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2224.rebuild();" onclick="PDRTJS_1209223_post_2224.rate(4);" onmouseover="PDRTJS_1209223_post_2224.hover(4);" id="PDRTJS_1209223_post_2224_stars_4" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2224.rebuild();" onclick="PDRTJS_1209223_post_2224.rate(5);" onmouseover="PDRTJS_1209223_post_2224.hover(5);" id="PDRTJS_1209223_post_2224_stars_5" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div></div><span style="float:left;">&nbsp;</span><div id="rating_info_1209223_post_2224" style="display:block;float:left;background:url(https://polldaddy.com/images/ratings/info@2x.png) no-repeat 3px 2px;width:16px;height:16px;cursor:pointer; background-size:12px 12px; " onclick="javascript:PDRTJS_1209223_post_2224.togglePopup();return false;"><span style="display:none;">i</span></div><div class="pd_popup_holder" id="pd_popup_holder_1209223_post_2224">&nbsp;</div><div class="rating-msg" id="PDRTJS_1209223_post_2224_msg" style="float:left; padding-left: 5px; text-align: left; font:normal normal /16px ; color: #;">4 Votes</div><p style="padding: 0px; margin: 0px; clear: both;"></p></div></div><div class="sharedaddy sd-sharing-enabled"><div class="robots-nocontent sd-block sd-social sd-social-icon sd-sharing"><h3 class="sd-title">Share this:</h3><div class="sd-content"><ul data-sharing-events-added="true"><li class="share-twitter"><a rel="nofollow noopener noreferrer" data-shared="sharing-twitter-2224" class="share-twitter sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=twitter&amp;nb=1" target="_blank" title="Click to share on Twitter"><span></span><span class="sharing-screen-reader-text">Click to share on Twitter (Opens in new window)</span></a></li><li class="share-reddit"><a rel="nofollow noopener noreferrer" data-shared="" class="share-reddit sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=reddit&amp;nb=1" target="_blank" title="Click to share on Reddit"><span></span><span class="sharing-screen-reader-text">Click to share on Reddit (Opens in new window)</span></a></li><li class="share-tumblr"><a rel="nofollow noopener noreferrer" data-shared="" class="share-tumblr sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=tumblr&amp;nb=1" target="_blank" title="Click to share on Tumblr"><span></span><span class="sharing-screen-reader-text">Click to share on Tumblr (Opens in new window)</span></a></li><li class="share-pinterest"><a rel="nofollow noopener noreferrer" data-shared="sharing-pinterest-2224" class="share-pinterest sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=pinterest&amp;nb=1" target="_blank" title="Click to share on Pinterest"><span></span><span class="sharing-screen-reader-text">Click to share on Pinterest (Opens in new window)</span></a></li><li class="share-linkedin"><a rel="nofollow noopener noreferrer" data-shared="sharing-linkedin-2224" class="share-linkedin sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=linkedin&amp;nb=1" target="_blank" title="Click to share on LinkedIn"><span></span><span class="sharing-screen-reader-text">Click to share on LinkedIn (Opens in new window)</span></a></li><li class="share-email share-service-visible"><a rel="nofollow noopener noreferrer" data-shared="" class="share-email sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=email&amp;nb=1" target="_blank" title="Click to email this to a friend"><span></span><span class="sharing-screen-reader-text">Click to email this to a friend (Opens in new window)</span></a></li><li class="share-facebook"><a rel="nofollow noopener noreferrer" data-shared="sharing-facebook-2224" class="share-facebook sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=facebook&amp;nb=1" target="_blank" title="Click to share on Facebook"><span></span><span class="sharing-screen-reader-text">Click to share on Facebook (Opens in new window)</span></a></li><li class="share-jetpack-whatsapp"><a rel="nofollow noopener noreferrer" data-shared="" class="share-jetpack-whatsapp sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?share=jetpack-whatsapp&amp;nb=1" target="_blank" title="Click to share on WhatsApp"><span></span><span class="sharing-screen-reader-text">Click to share on WhatsApp (Opens in new window)</span></a></li><li class="share-end"></li></ul></div></div></div><div class="sharedaddy sd-block sd-like jetpack-likes-widget-wrapper jetpack-likes-widget-loaded" id="like-post-wrapper-11065590-2224-617d6f1911ff8" data-src="//widgets.wp.com/likes/index.html?ver=20210831#blog_id=11065590&amp;post_id=2224&amp;origin=smittytone.wordpress.com&amp;obj_id=11065590-2224-617d6f1911ff8&amp;domain=blog.smittytone.net" data-name="like-post-frame-11065590-2224-617d6f1911ff8" data-title="Like or Reblog"><h3 class="sd-title">Like this:</h3><div class="likes-widget-placeholder post-likes-widget-placeholder" style="height: 55px; display: none;"><span class="button"><span>Like</span></span> <span class="loading">Loading...</span></div><iframe class="post-likes-widget jetpack-likes-widget" name="like-post-frame-11065590-2224-617d6f1911ff8" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/index.html" height="55px" width="100%" frameborder="0" title="Like or Reblog"></iframe><span class="sd-text-color"></span><a class="sd-link-color"></a></div>
<div id="jp-relatedposts" class="jp-relatedposts" style="display: block;">
	<h3 class="jp-relatedposts-headline"><em>Related</em></h3>
<div class="jp-relatedposts-items jp-relatedposts-items-visual jp-relatedposts-grid "><div class="jp-relatedposts-post jp-relatedposts-post0 jp-relatedposts-post-thumbs" data-post-id="2932" data-post-format="false"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/08/20/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-one/?relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=0&amp;relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=0" title="How to build a cellular IoT device with the Raspberry Pi Pico — part one, the hardware" data-origin="2224" data-position="0"><img class="jp-relatedposts-post-img" loading="lazy" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/p1020125.jpg" width="193" alt="" height="110" srcset="https://smittytone.files.wordpress.com/2021/08/p1020125.jpg?w=193&amp;h=110&amp;crop=1&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/08/p1020125.jpg?w=350&amp;h=200&amp;crop=1" scale="2"></a><h4 class="jp-relatedposts-post-title"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/08/20/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-one/?relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=0&amp;relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=0" title="How to build a cellular IoT device with the Raspberry Pi Pico — part one, the hardware" data-origin="2224" data-position="0">How to build a cellular IoT device with the Raspberry Pi Pico — part one, the&nbsp;hardware</a></h4><p class="jp-relatedposts-post-excerpt">To turn the Raspberry Pi Pico into an Internet of Things (IoT) device, you need to add wireless connectivity. I thought I’d give it go, to see how straightforward it might be to connect the Pico to cellular networks and have a bare-metal app written in C++ run the show.…</p><time class="jp-relatedposts-post-date" datetime="August 20, 2021" style="display: block;">August 20, 2021</time><p class="jp-relatedposts-post-context">In "How To (Pi)"</p></div><div class="jp-relatedposts-post jp-relatedposts-post1 jp-relatedposts-post-thumbs" data-post-id="2776" data-post-format="false"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/02/raspberry-pi-pico-proxies-pimoroni-tiny-2040-adafruit-qt-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=1&amp;relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=1" title="Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py RP2040" data-origin="2224" data-position="1"><img class="jp-relatedposts-post-img" loading="lazy" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/p1020086-1.jpg" width="193" alt="" height="110" srcset="https://smittytone.files.wordpress.com/2021/07/p1020086-1.jpg?w=193&amp;h=110&amp;crop=1&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/07/p1020086-1.jpg?w=350&amp;h=200&amp;crop=1" scale="2"></a><h4 class="jp-relatedposts-post-title"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/02/raspberry-pi-pico-proxies-pimoroni-tiny-2040-adafruit-qt-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=1&amp;relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=1" title="Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py RP2040" data-origin="2224" data-position="1">Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py&nbsp;RP2040</a></h4><p class="jp-relatedposts-post-excerpt">Having spent some time with the Raspberry Pi Pico, I thought it was time to try out some of the other RP2040-based development boards that have become available. When it launched the Pico, the Raspberry Pi Foundation said it would make its RP2040 microcontroller available to third-party board makers. Retailers…</p><time class="jp-relatedposts-post-date" datetime="July 2, 2021" style="display: block;">July 2, 2021</time><p class="jp-relatedposts-post-context">In "Raspberry Pi"</p></div><div class="jp-relatedposts-post jp-relatedposts-post2 jp-relatedposts-post-thumbs" data-post-id="2858" data-post-format="false"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/24/how-to-pop-up-a-picoprobe-from-the-adafruit-qy-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=2&amp;relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=2" title="How to pop up a Picoprobe from the Adafruit QT Py RP2040" data-origin="2224" data-position="2"><img class="jp-relatedposts-post-img" loading="lazy" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/p1020082.jpg" width="193" alt="" height="110" srcset="https://smittytone.files.wordpress.com/2021/07/p1020082.jpg?w=193&amp;h=110&amp;crop=1&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/07/p1020082.jpg?w=350&amp;h=200&amp;crop=1" scale="2"></a><h4 class="jp-relatedposts-post-title"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/24/how-to-pop-up-a-picoprobe-from-the-adafruit-qy-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=2&amp;relatedposts_hit=1&amp;relatedposts_origin=2224&amp;relatedposts_position=2" title="How to pop up a Picoprobe from the Adafruit QT Py RP2040" data-origin="2224" data-position="2">How to pop up a Picoprobe from the Adafruit QT Py&nbsp;RP2040</a></h4><p class="jp-relatedposts-post-excerpt">A little while back I wrote about Adafruit's QT Py RP2040 and how it makes a nice, compact Picoprobe. That’s a Raspberry Pi RP2040-based device used as a bridge between your computer and a target device for debugging work using Single Wire Debug (SWD). I first used the QT Py…</p><time class="jp-relatedposts-post-date" datetime="July 24, 2021" style="display: block;">July 24, 2021</time><p class="jp-relatedposts-post-context">In "How To (Pi)"</p></div></div></div></div>					</div><!-- .entry-content -->
		
		<footer class="entry-meta">
			This entry was posted in <a href="https://blog.smittytone.net/category/how-to-mac/" rel="category tag">How To (Mac)</a>, <a href="https://blog.smittytone.net/category/how-to-pi/" rel="category tag">How To (Pi)</a>, <a href="https://blog.smittytone.net/category/raspberry-pi/" rel="category tag">Raspberry Pi</a> and tagged <a href="https://blog.smittytone.net/tag/c-2/" rel="tag">C++</a>, <a href="https://blog.smittytone.net/tag/c-c/" rel="tag">c/c++</a>, <a href="https://blog.smittytone.net/tag/mac/" rel="tag">Mac</a>, <a href="https://blog.smittytone.net/tag/macos/" rel="tag">macos</a>, <a href="https://blog.smittytone.net/tag/osx/" rel="tag">osx</a>, <a href="https://blog.smittytone.net/tag/pico/" rel="tag">Pico</a>, <a href="https://blog.smittytone.net/tag/raspberry-pi/" rel="tag">Raspberry Pi</a> on <a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/" title="9:49 am" rel="bookmark"><time class="entry-date" datetime="2021-02-02T09:49:36+00:00">February 2, 2021</time></a><span class="by-author"> by <span class="author vcard"><a class="url fn n" href="https://blog.smittytone.net/author/smittytone/" title="View all posts by smittytone" rel="author">smittytone</a></span></span>.								</footer><!-- .entry-meta -->
	</article><!-- #post -->

				<nav class="nav-single">
					<h3 class="assistive-text">Post navigation</h3>
					<span class="nav-previous"><a href="https://blog.smittytone.net/2021/01/23/first-look-the-raspberry-pi-pico-on-mac/" rel="prev"><span class="meta-nav">←</span> A first look at a MicroPython marvel: the Raspberry Pi Pico, in partnership with a&nbsp;Mac</a></span>
					<span class="nav-next"><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/" rel="next">How to debug a Raspberry Pi Pico with a Mac, SWD and… another&nbsp;Pico <span class="meta-nav">→</span></a></span>
				</nav><!-- .nav-single -->

				
<div id="comments" class="comments-area">

	
			<h2 class="comments-title">
			4 thoughts on “<span>How to program the Raspberry Pi Pico in C on a&nbsp;Mac</span>”		</h2>

		<ol class="commentlist">
				<li class="comment even thread-even depth-1 highlander-comment" id="li-comment-5878">
		<article id="comment-5878" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/e6bd53df77ea4c05c95a939da60674b4.png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://2.gravatar.com/avatar/e6bd53df77ea4c05c95a939da60674b4?s=44&amp;d=https%3A%2F%2F2.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-e6bd53df77ea4c05c95a939da60674b4-0"><cite><b class="fn">Mike</b> </cite><a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/#comment-5878"><time datetime="2021-03-12T16:50:24+00:00">March 12, 2021 at 4:50 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Hm, nice but I wait for platformio-support</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				</li><!-- #comment-## -->
	<li class="pingback odd alt thread-odd thread-alt depth-1 highlander-comment" id="comment-5876">
		<p>Pingback: <a href="https://blog.adafruit.com/2021/03/12/how-to-program-the-raspberry-pi-pico-in-c-on-a-mac/" rel="external nofollow ugc" class="url">How to program the Raspberry Pi Pico in C on a Mac « Adafruit Industries – Makers, hackers, artists, designers and engineers!</a> </p>
	</li><!-- #comment-## -->
	<li class="pingback even thread-even depth-1 highlander-comment" id="comment-5056">
		<p>Pingback: <a href="https://www.recantha.co.uk/blog/?p=20827" rel="external nofollow ugc" class="url">How to develop for the Raspberry Pi Pico on a Mac – Raspberry Pi Pod and micro:bit base</a> </p>
	</li><!-- #comment-## -->
	<li class="comment odd alt thread-odd thread-alt depth-1 highlander-comment" id="li-comment-4904">
		<article id="comment-4904" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/ad516503a11cd5ca435acc9bb6523536.png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://1.gravatar.com/avatar/707e748a68fce249a6f61a55ebd92763?s=44&amp;d=https%3A%2F%2F1.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-707e748a68fce249a6f61a55ebd92763-0"><cite><b class="fn">Dycey</b> </cite><a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/#comment-4904"><time datetime="2021-02-04T21:22:00+00:00">February 4, 2021 at 9:22 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Noice! Thanks Tone, I’ve ordered a pico to play with.</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				</li><!-- #comment-## -->
		</ol><!-- .commentlist -->

		
				<p class="nocomments">Comments are closed.</p>
		
	
	
</div><!-- #comments .comments-area -->

			
		</div><!-- #content -->
	</div><!-- #primary -->


			<div id="secondary" class="widget-area" role="complementary">
						<aside id="follow_button_widget-3" class="widget widget_follow_button_widget">
		<iframe src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/index(1).html" width="100%" height="20" frameborder="0" scrolling="no"></iframe>
		<script type="text/javascript">(function(d){var f = d.getElementsByTagName('SCRIPT')[0], p = d.createElement('SCRIPT');p.type = 'text/javascript';p.async = true;p.src = '//widgets.wp.com/platform.js';f.parentNode.insertBefore(p,f);}(document));</script>

		</aside><aside id="block-3" class="widget widget_block widget_media_image">
<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://merch.smittytone.net/" target="_blank"><img loading="lazy" width="250" height="229" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/shirts.png" alt="" class="wp-image-2955" srcset="https://smittytone.files.wordpress.com/2021/08/shirts.png?w=250&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/08/shirts.png?w=1024" scale="2"></a><figcaption>smittytone’s retro tech t-shirts</figcaption></figure></div>
</aside><aside id="media_image-3" class="widget widget_media_image"><h3 class="widget-title">Program the Raspberry Pi Pico</h3><style>.widget.widget_media_image { overflow: hidden; }.widget.widget_media_image img { height: auto; max-width: 100%; }</style><a href="https://blog.smittytone.net/tag/pico/"><img width="1120" height="514" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/pico(1).jpg" class="image wp-image-2238  attachment-1120x514 size-1120x514" alt="" loading="lazy" style="max-width: 100%; height: auto;" srcset="https://smittytone.files.wordpress.com/2021/02/pico.jpg 1120w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=1024 1024w" sizes="(max-width: 1120px) 100vw, 1120px" data-attachment-id="2238" data-permalink="https://blog.smittytone.net/pico/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg" data-orig-size="1120,514" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="pico" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=625"></a></aside>
		<aside id="recent-posts-4" class="widget widget_recent_entries">
		<h3 class="widget-title">Latest Items</h3>
		<ul>
											<li>
					<a href="https://blog.smittytone.net/2021/10/16/first-look-pimoroni-picosystem-hackable-handheld-games-console/">First look: Pimoroni’s PicoSystem hackable handheld games&nbsp;console</a>
											<span class="post-date">October 16, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/10/02/clive-sinclair-1941-2021-part-three-resurgam/">Clive Sinclair (1941-2021) Part three —&nbsp;resurgam</a>
											<span class="post-date">October 2, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/09/24/clive-sinclair-1940-2021-part-two-radionics-last-great-hope-the-microcomputer/">Clive Sinclair (1940-2021) Part two —&nbsp;Radionics’ last, great hope: the&nbsp;microcomputer</a>
											<span class="post-date">September 24, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/09/16/sir-clive-sinclair-1940-2021-how-it-all-began/">Clive Sinclair (1940-2021) Part one — how it all&nbsp;began</a>
											<span class="post-date">September 16, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/08/30/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-two/">How to build a cellular IoT device with the Raspberry Pi Pico — part two, the&nbsp;code</a>
											<span class="post-date">August 30, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/08/20/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-one/">How to build a cellular IoT device with the Raspberry Pi Pico — part one, the&nbsp;hardware</a>
											<span class="post-date">August 20, 2021</span>
									</li>
					</ul>

		</aside><aside id="media_image-5" class="widget widget_media_image"><h3 class="widget-title">Enjoyed using this site? Tip me!</h3><style>.widget.widget_media_image { overflow: hidden; }.widget.widget_media_image img { height: auto; max-width: 100%; }</style><img width="625" height="694" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/img_0604.jpg" class="image wp-image-2614  attachment-full size-full" alt="Tip QR Code" loading="lazy" style="max-width: 100%; height: auto;" srcset="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=625&amp;h=694 625w, https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=135&amp;h=150 135w, https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=270&amp;h=300 270w, https://smittytone.files.wordpress.com/2021/04/img_0604.jpg 648w" sizes="(max-width: 625px) 100vw, 625px" data-attachment-id="2614" data-permalink="https://blog.smittytone.net/img_0604/" data-orig-file="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg" data-orig-size="648,720" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="IMG_0604" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=270" data-large-file="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=625"></aside><aside id="custom_html-3" class="widget_text widget widget_custom_html"><h3 class="widget-title">My Sites</h3><div class="textwidget custom-html-widget"><ul>
	<li><a href="https://smittytone.net/">smittytone’s software stack</a></li>
	<li><a href="https://code.smittytone.net/">GitHub</a></li>
	<li><a href="https://www.linkedin.com/in/smittytone/">LinkedIn</a></li>
	<li><a href="https://merch.smittytone.net/">Merch</a></li>
</ul></div></aside><aside id="pages-4" class="widget widget_pages"><h3 class="widget-title">Other Items</h3>
			<ul>
				<li class="page_item page-item-2"><a href="https://blog.smittytone.net/about/">About ‘Smittytone Messes with&nbsp;Micros’</a></li>
<li class="page_item page-item-1477"><a href="https://blog.smittytone.net/pi-knowledgebase/">Raspberry Pi Knowledgebase</a></li>
			</ul>

			</aside><aside id="categories-4" class="widget widget_categories"><h3 class="widget-title">Site Topics</h3>
			<ul>
					<li class="cat-item cat-item-4213"><a href="https://blog.smittytone.net/category/apps/">apps</a>
</li>
	<li class="cat-item cat-item-4843"><a href="https://blog.smittytone.net/category/hacks/">Hacks</a>
</li>
	<li class="cat-item cat-item-9333085"><a href="https://blog.smittytone.net/category/how-to-mac/">How To (Mac)</a>
</li>
	<li class="cat-item cat-item-323292718"><a href="https://blog.smittytone.net/category/how-to-pi/">How To (Pi)</a>
</li>
	<li class="cat-item cat-item-2121118"><a href="https://blog.smittytone.net/category/iot/">IoT</a>
</li>
	<li class="cat-item cat-item-808"><a href="https://blog.smittytone.net/category/mac/">Mac</a>
</li>
	<li class="cat-item cat-item-120"><a href="https://blog.smittytone.net/category/mobile/">Mobile</a>
</li>
	<li class="cat-item cat-item-196"><a href="https://blog.smittytone.net/category/programming/">Programming</a>
</li>
	<li class="cat-item cat-item-49695267"><a href="https://blog.smittytone.net/category/raspberry-pi/">Raspberry Pi</a>
</li>
	<li class="cat-item cat-item-1445"><a href="https://blog.smittytone.net/category/retro/">Retro</a>
</li>
	<li class="cat-item cat-item-309"><a href="https://blog.smittytone.net/category/reviews/">Reviews</a>
</li>
	<li class="cat-item cat-item-287954"><a href="https://blog.smittytone.net/category/sidelines/">Sidelines</a>
</li>
	<li class="cat-item cat-item-36477"><a href="https://blog.smittytone.net/category/vintage-computing/">Vintage Computing</a>
</li>
	<li class="cat-item cat-item-362282"><a href="https://blog.smittytone.net/category/webwork/">Webwork</a>
</li>
	<li class="cat-item cat-item-355"><a href="https://blog.smittytone.net/category/wireless/">Wireless</a>
</li>
			</ul>

			</aside><aside id="follow_button_widget-5" class="widget widget_follow_button_widget">
		<iframe src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/index(2).html" width="100%" height="20" frameborder="0" scrolling="no"></iframe>
		<script type="text/javascript">(function(d){var f = d.getElementsByTagName('SCRIPT')[0], p = d.createElement('SCRIPT');p.type = 'text/javascript';p.async = true;p.src = '//widgets.wp.com/platform.js';f.parentNode.insertBefore(p,f);}(document));</script>

		</aside><aside id="block-4" class="widget widget_block widget_text">
<p></p>
</aside>		</div><!-- #secondary -->
		</div><!-- #main .wrapper -->
	<footer id="colophon" role="contentinfo">
		<div class="site-info">
									<a href="https://wordpress.com/?ref=footer_custom_powered" rel="nofollow">Website Powered by WordPress.com</a>.
		</div><!-- .site-info -->
	</footer><!-- #colophon -->
</div><!-- #page -->

<!--  -->
<script src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/gprofiles.js" id="grofiles-cards-js"></script>
<script id="wpgroho-js-extra">
var WPGroHo = {"my_hash":""};
</script>
<script crossorigin="anonymous" type="text/javascript" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/wpgroho.js"></script>

	<script>
		// Initialize and attach hovercards to all gravatars
		( function() {
			function init() {
				if ( typeof Gravatar === 'undefined' ) {
					return;
				}

				if ( typeof Gravatar.init !== 'function' ) {
					return;
				}

				Gravatar.profile_cb = function ( hash, id ) {
					WPGroHo.syncProfileData( hash, id );
				};

				Gravatar.my_hash = WPGroHo.my_hash;
				Gravatar.init( 'body', '#wp-admin-bar-my-account' );
			}

			if ( document.readyState !== 'loading' ) {
				init();
			} else {
				document.addEventListener( 'DOMContentLoaded', init );
			}
		} )();
	</script>

		<div style="display:none">
	<div class="grofile-hash-map-e6bd53df77ea4c05c95a939da60674b4">
	</div>
	<div class="grofile-hash-map-707e748a68fce249a6f61a55ebd92763">
	</div>
	</div>
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-dark-grayscale"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 0.49803921568627"></fefuncr><fefuncg type="table" tableValues="0 0.49803921568627"></fefuncg><fefuncb type="table" tableValues="0 0.49803921568627"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-grayscale"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 1"></fefuncr><fefuncg type="table" tableValues="0 1"></fefuncg><fefuncb type="table" tableValues="0 1"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-purple-yellow"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.54901960784314 0.98823529411765"></fefuncr><fefuncg type="table" tableValues="0 1"></fefuncg><fefuncb type="table" tableValues="0.71764705882353 0.25490196078431"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-blue-red"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 1"></fefuncr><fefuncg type="table" tableValues="0 0.27843137254902"></fefuncg><fefuncb type="table" tableValues="0.5921568627451 0.27843137254902"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-midnight"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 0"></fefuncr><fefuncg type="table" tableValues="0 0.64705882352941"></fefuncg><fefuncb type="table" tableValues="0 1"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-magenta-yellow"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.78039215686275 1"></fefuncr><fefuncg type="table" tableValues="0 0.94901960784314"></fefuncg><fefuncb type="table" tableValues="0.35294117647059 0.47058823529412"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-purple-green"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.65098039215686 0.40392156862745"></fefuncr><fefuncg type="table" tableValues="0 1"></fefuncg><fefuncb type="table" tableValues="0.44705882352941 0.4"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-blue-orange"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.098039215686275 1"></fefuncr><fefuncg type="table" tableValues="0 0.66274509803922"></fefuncg><fefuncb type="table" tableValues="0.84705882352941 0.41960784313725"></fefuncb></fecomponenttransfer></filter></defs></svg>
<script>
window.addEventListener( "load", function( event ) {
	var link = document.createElement( "link" );
	link.href = "https://s0.wp.com/wp-content/mu-plugins/actionbar/actionbar.css?v=20210915";
	link.type = "text/css";
	link.rel = "stylesheet";
	document.head.appendChild( link );

	var script = document.createElement( "script" );
	script.src = "https://s0.wp.com/wp-content/mu-plugins/actionbar/actionbar.js?v=20211021";
	script.defer = true;
	document.body.appendChild( script );
} );
</script>

			<div id="jp-carousel-loading-overlay">
			<div id="jp-carousel-loading-wrapper">
				<span id="jp-carousel-library-loading">&nbsp;</span>
			</div>
		</div>
		<div class="jp-carousel-overlay" style="display: none;">

		<div class="jp-carousel-container">
			<!-- The Carousel Swiper -->
			<div class="jp-carousel-wrap swiper-container jp-carousel-swiper-container jp-carousel-transitions" itemscope="" itemtype="https://schema.org/ImageGallery">
				<div class="jp-carousel swiper-wrapper"></div>
				<div class="jp-swiper-button-prev swiper-button-prev">
					<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
						<mask id="maskPrev" mask-type="alpha" maskUnits="userSpaceOnUse" x="8" y="6" width="9" height="12">
							<path d="M16.2072 16.59L11.6496 12L16.2072 7.41L14.8041 6L8.8335 12L14.8041 18L16.2072 16.59Z" fill="white"></path>
						</mask>
						<g mask="url(#maskPrev)">
							<rect x="0.579102" width="23.8823" height="24" fill="#FFFFFF"></rect>
						</g>
					</svg>
				</div>
				<div class="jp-swiper-button-next swiper-button-next">
					<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
						<mask id="maskNext" mask-type="alpha" maskUnits="userSpaceOnUse" x="8" y="6" width="8" height="12">
							<path d="M8.59814 16.59L13.1557 12L8.59814 7.41L10.0012 6L15.9718 12L10.0012 18L8.59814 16.59Z" fill="white"></path>
						</mask>
						<g mask="url(#maskNext)">
							<rect x="0.34375" width="23.8822" height="24" fill="#FFFFFF"></rect>
						</g>
					</svg>
				</div>
			</div>
			<!-- The main close buton -->
			<div class="jp-carousel-close-hint">
				<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
					<mask id="maskClose" mask-type="alpha" maskUnits="userSpaceOnUse" x="5" y="5" width="15" height="14">
						<path d="M19.3166 6.41L17.9135 5L12.3509 10.59L6.78834 5L5.38525 6.41L10.9478 12L5.38525 17.59L6.78834 19L12.3509 13.41L17.9135 19L19.3166 17.59L13.754 12L19.3166 6.41Z" fill="white"></path>
					</mask>
					<g mask="url(#maskClose)">
						<rect x="0.409668" width="23.8823" height="24" fill="#FFFFFF"></rect>
					</g>
				</svg>
			</div>
			<!-- Image info, comments and meta -->
			<div class="jp-carousel-info">
				<div class="jp-carousel-info-footer">
					<div class="jp-carousel-pagination-container">
						<div class="jp-swiper-pagination swiper-pagination"></div>
						<div class="jp-carousel-pagination"></div>
					</div>
					<div class="jp-carousel-photo-title-container">
						<h2 class="jp-carousel-photo-caption"></h2>
					</div>
					<div class="jp-carousel-photo-icons-container">
						<a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/#" class="jp-carousel-icon-btn jp-carousel-icon-info" aria-label="Toggle photo metadata visibility">
							<span class="jp-carousel-icon">
								<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
									<mask id="maskInfo" mask-type="alpha" maskUnits="userSpaceOnUse" x="2" y="2" width="21" height="20">
										<path fill-rule="evenodd" clip-rule="evenodd" d="M12.7537 2C7.26076 2 2.80273 6.48 2.80273 12C2.80273 17.52 7.26076 22 12.7537 22C18.2466 22 22.7046 17.52 22.7046 12C22.7046 6.48 18.2466 2 12.7537 2ZM11.7586 7V9H13.7488V7H11.7586ZM11.7586 11V17H13.7488V11H11.7586ZM4.79292 12C4.79292 16.41 8.36531 20 12.7537 20C17.142 20 20.7144 16.41 20.7144 12C20.7144 7.59 17.142 4 12.7537 4C8.36531 4 4.79292 7.59 4.79292 12Z" fill="white"></path>
									</mask>
									<g mask="url(#maskInfo)">
										<rect x="0.8125" width="23.8823" height="24" fill="#FFFFFF"></rect>
									</g>
								</svg>
							</span>
						</a>
												<a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/#" class="jp-carousel-icon-btn jp-carousel-icon-comments" aria-label="Toggle photo comments visibility">
							<span class="jp-carousel-icon">
								<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
									<mask id="maskComments" mask-type="alpha" maskUnits="userSpaceOnUse" x="2" y="2" width="21" height="20">
										<path fill-rule="evenodd" clip-rule="evenodd" d="M4.3271 2H20.2486C21.3432 2 22.2388 2.9 22.2388 4V16C22.2388 17.1 21.3432 18 20.2486 18H6.31729L2.33691 22V4C2.33691 2.9 3.2325 2 4.3271 2ZM6.31729 16H20.2486V4H4.3271V18L6.31729 16Z" fill="white"></path>
									</mask>
									<g mask="url(#maskComments)">
										<rect x="0.34668" width="23.8823" height="24" fill="#FFFFFF"></rect>
									</g>
								</svg>

								<span class="jp-carousel-has-comments-indicator" aria-label="This image has comments."></span>
							</span>
						</a>
											</div>
				</div>
				<div class="jp-carousel-info-extra">
					<div class="jp-carousel-info-content-wrapper">
						<div class="jp-carousel-photo-title-container">
							<h2 class="jp-carousel-photo-title"></h2>
						</div>
						<div class="jp-carousel-comments-wrapper">
															<div id="jp-carousel-comments-loading">
									<span>Loading Comments...</span>
								</div>
								<div class="jp-carousel-comments"></div>
								<div id="jp-carousel-comment-form-container">
									<span id="jp-carousel-comment-form-spinner">&nbsp;</span>
									<div id="jp-carousel-comment-post-results"></div>
																														<form id="jp-carousel-comment-form">
												<label for="jp-carousel-comment-form-comment-field" class="screen-reader-text">Write a Comment...</label>
												<textarea name="comment" class="jp-carousel-comment-form-field jp-carousel-comment-form-textarea" id="jp-carousel-comment-form-comment-field" placeholder="Write a Comment..."></textarea>
												<div id="jp-carousel-comment-form-submit-and-info-wrapper">
													<div id="jp-carousel-comment-form-commenting-as">
																													<fieldset>
																<label for="jp-carousel-comment-form-email-field">Email (Required)</label>
																<input type="text" name="email" class="jp-carousel-comment-form-field jp-carousel-comment-form-text-field" id="jp-carousel-comment-form-email-field">
															</fieldset>
															<fieldset>
																<label for="jp-carousel-comment-form-author-field">Name (Required)</label>
																<input type="text" name="author" class="jp-carousel-comment-form-field jp-carousel-comment-form-text-field" id="jp-carousel-comment-form-author-field">
															</fieldset>
															<fieldset>
																<label for="jp-carousel-comment-form-url-field">Website</label>
																<input type="text" name="url" class="jp-carousel-comment-form-field jp-carousel-comment-form-text-field" id="jp-carousel-comment-form-url-field">
															</fieldset>
																											</div>
													<input type="submit" name="submit" class="jp-carousel-comment-form-button" id="jp-carousel-comment-form-button-submit" value="Post Comment">
												</div>
											</form>
																											</div>
													</div>
						<div class="jp-carousel-image-meta">
							<div class="jp-carousel-title-and-caption">
								<div class="jp-carousel-photo-info">
									<h3 class="jp-carousel-caption" itemprop="caption description"></h3>
								</div>

								<div class="jp-carousel-photo-description"></div>
							</div>
							<ul class="jp-carousel-image-exif" style="display: none;"></ul>
							<a class="jp-carousel-image-download" target="_blank" style="display: none;">
								<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
									<mask id="mask0" mask-type="alpha" maskUnits="userSpaceOnUse" x="3" y="3" width="19" height="18">
										<path fill-rule="evenodd" clip-rule="evenodd" d="M5.84615 5V19H19.7775V12H21.7677V19C21.7677 20.1 20.8721 21 19.7775 21H5.84615C4.74159 21 3.85596 20.1 3.85596 19V5C3.85596 3.9 4.74159 3 5.84615 3H12.8118V5H5.84615ZM14.802 5V3H21.7677V10H19.7775V6.41L9.99569 16.24L8.59261 14.83L18.3744 5H14.802Z" fill="white"></path>
									</mask>
									<g mask="url(#mask0)">
										<rect x="0.870605" width="23.8823" height="24" fill="#FFFFFF"></rect>
									</g>
								</svg>
								<span class="jp-carousel-download-text"></span>
							</a>
							<div class="jp-carousel-image-map" style="display: none;"></div>
						</div>
					</div>
				</div>
			</div>
		</div>

		</div>
		
	<script type="text/javascript">
		window.WPCOM_sharing_counts = {"https:\/\/blog.smittytone.net\/2021\/02\/02\/program-raspberry-pi-pico-c-mac\/":2224};
	</script>
							
<script crossorigin="anonymous" type="text/javascript" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(6)"></script>
<script type="text/javascript">
	(function(){
		var corecss = document.createElement('link');
		var themecss = document.createElement('link');
		var corecssurl = "https://s0.wp.com/wp-content/plugins/syntaxhighlighter/syntaxhighlighter3/styles/shCore.css?ver=3.0.9b";
		if ( corecss.setAttribute ) {
				corecss.setAttribute( "rel", "stylesheet" );
				corecss.setAttribute( "type", "text/css" );
				corecss.setAttribute( "href", corecssurl );
		} else {
				corecss.rel = "stylesheet";
				corecss.href = corecssurl;
		}
		document.head.appendChild( corecss );
		var themecssurl = "https://s0.wp.com/wp-content/plugins/syntaxhighlighter/syntaxhighlighter3/styles/shThemeDefault.css?m=1363304414h&amp;ver=3.0.9b";
		if ( themecss.setAttribute ) {
				themecss.setAttribute( "rel", "stylesheet" );
				themecss.setAttribute( "type", "text/css" );
				themecss.setAttribute( "href", themecssurl );
		} else {
				themecss.rel = "stylesheet";
				themecss.href = themecssurl;
		}
		document.head.appendChild( themecss );
	})();
	SyntaxHighlighter.config.strings.expandSource = '+ expand source';
	SyntaxHighlighter.config.strings.help = '?';
	SyntaxHighlighter.config.strings.alert = 'SyntaxHighlighter\n\n';
	SyntaxHighlighter.config.strings.noBrush = 'Can\'t find brush for: ';
	SyntaxHighlighter.config.strings.brushNotHtmlScript = 'Brush wasn\'t configured for html-script option: ';
	SyntaxHighlighter.defaults['pad-line-numbers'] = false;
	SyntaxHighlighter.defaults['toolbar'] = false;
	SyntaxHighlighter.all();

	// Infinite scroll support
	if ( typeof( jQuery ) !== 'undefined' ) {
		jQuery( function( $ ) {
			$( document.body ).on( 'post-load', function() {
				SyntaxHighlighter.highlight();
			} );
		} );
	}
</script>
<link rel="stylesheet" id="all-css-0-2" href="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(7)" type="text/css" media="all">
<script id="coblocks-lightbox-js-extra">
var coblocksLigthboxData = {"closeLabel":"Close Gallery","leftLabel":"Previous","rightLabel":"Next"};
</script>
<script id="jetpack-carousel-js-extra">
var jetpackSwiperLibraryPath = {"url":"\/wp-content\/mu-plugins\/carousel\/swiper-bundle.js"};
var jetpackCarouselStrings = {"widths":[370,700,1000,1200,1400,2000],"is_logged_in":"","lang":"en","ajaxurl":"https:\/\/blog.smittytone.net\/wp-admin\/admin-ajax.php","nonce":"697ef9117f","display_exif":"1","display_comments":"1","display_geo":"1","single_image_gallery":"1","single_image_gallery_media_file":"","background_color":"black","comment":"Comment","post_comment":"Post Comment","write_comment":"Write a Comment...","loading_comments":"Loading Comments...","download_original":"View full size <span class=\"photo-size\">{0}<span class=\"photo-size-times\">\u00d7<\/span>{1}<\/span>","no_comment_text":"Please be sure to submit some text with your comment.","no_comment_email":"Please provide an email address to comment.","no_comment_author":"Please provide your name to comment.","comment_post_error":"Sorry, but there was an error posting your comment. Please try again later.","comment_approved":"Your comment was approved.","comment_unapproved":"Your comment is in moderation.","camera":"Camera","aperture":"Aperture","shutter_speed":"Shutter Speed","focal_length":"Focal Length","copyright":"Copyright","comment_registration":"0","require_name_email":"1","login_url":"https:\/\/smittytone.wordpress.com\/wp-login.php?redirect_to=https%3A%2F%2Fblog.smittytone.net%2F2021%2F02%2F02%2Fprogram-raspberry-pi-pico-c-mac%2F","blog_id":"11065590","meta_data":["camera","aperture","shutter_speed","focal_length","copyright"],"stats_query_args":"blog=11065590&v=wpcom&tz=0&user_id=0&subd=smittytone","is_public":"1"};
</script>
<script crossorigin="anonymous" type="text/javascript" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(8)"></script>
<script id="crowdsignal-rating-js-before">
<!--//--><![CDATA[//><!--
PDRTJS_settings_1209223_post_2224={"id":1209223,"unique_id":"wp-post-2224","title":"How%20to%20program%20the%20Raspberry%20Pi%20Pico%20in%20C%20on%20a%26nbsp%3BMac","permalink":"https:\/\/blog.smittytone.net\/2021\/02\/02\/program-raspberry-pi-pico-c-mac\/","item_id":"_post_2224"}; if ( typeof PDRTJS_RATING !== 'undefined' ){if ( typeof PDRTJS_1209223_post_2224 == 'undefined' ){PDRTJS_1209223_post_2224 = new PDRTJS_RATING( PDRTJS_settings_1209223_post_2224 );}}
//--><!]]>
</script>
<script src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/rating.js" id="crowdsignal-rating-js"></script>
<script id="sharing-js-js-extra">
var sharing_js_options = {"lang":"en","counts":"1","is_stats_active":"1"};
</script>
<script async="true" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/count.json"></script><script async="true" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource(9)"></script><script crossorigin="anonymous" type="text/javascript" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/sharing.js"></script>
<script type="text/javascript">
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-twitter' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-twitter' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomtwitter', 'menubar=1,resizable=1,width=600,height=350' );
						return false;
					}
				} );
			} )();
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-tumblr' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-tumblr' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomtumblr', 'menubar=1,resizable=1,width=450,height=450' );
						return false;
					}
				} );
			} )();
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-linkedin' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-linkedin' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomlinkedin', 'menubar=1,resizable=1,width=580,height=450' );
						return false;
					}
				} );
			} )();
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-facebook' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-facebook' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomfacebook', 'menubar=1,resizable=1,width=600,height=400' );
						return false;
					}
				} );
			} )();
</script>
<script type="text/javascript">
// <![CDATA[
(function() {
try{
  if ( window.external &&'msIsSiteMode' in window.external) {
    if (window.external.msIsSiteMode()) {
      var jl = document.createElement('script');
      jl.type='text/javascript';
      jl.async=true;
      jl.src='/wp-content/plugins/ie-sitemode/custom-jumplist.php';
      var s = document.getElementsByTagName('script')[0];
      s.parentNode.insertBefore(jl, s);
    }
  }
}catch(e){}
})();
// ]]>
</script>	<iframe src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/master.html" scrolling="no" id="likes-master" name="likes-master" style="display:none;"></iframe>
	<div id="likes-other-gravatars">
		<div class="likes-text">
			<span>%d</span> bloggers like this:		</div>
		<ul class="wpl-avatars sd-like-gravatars"></ul>
	</div>
	
		<script src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/w.js" defer=""></script> <script type="text/javascript">
_tkq = window._tkq || [];
_stq = window._stq || [];
_tkq.push(['storeContext', {'blog_id':'11065590','blog_tz':'0','user_lang':'en','blog_lang':'en','user_id':'0'}]);
_stq.push(['view', {'blog':'11065590','v':'wpcom','tz':'0','user_id':'0','post':'2224','subd':'smittytone'}]);
_stq.push(['extra', {'crypt':'UE40eW5QN0p8M2Y/RE1TaVhzUzFMbjdWNHpwZGhTayxPSUFCMGNrd29+Smw0TDhnZmRTK0hlRi9QSGh6bi9GXVhBJWIlZlR5U1JMLU8/MkNtblkvY1dzK3YrWW16SXlfX2E4SWFOK25BfFZLYlslNCtuP19fb0tHaDkzcThPRSZdVmEsbldTUDF6VW5qYTdCVj1UMkYmL1U1dXhsR2xDRy4yJXVIRHd+Qnl5di5OaGFTbk0sTi9bTUhDOGNWRTV6X11ibGxnJjB5LnVdQnJLeFUsQi1ScisuT2dMYzhRVlRwY2dHMFg0RFN2XSV8SC8ybD1xZiw1QyVoTVFzY1dnTVZxak18R1ola28zTExvbS1SeVUsdm0sVStjeWFlZmJnVE8seDdIbC9iW294Umw1Zmo/dl00'}]);
_stq.push([ 'clickTrackerInit', '11065590', '2224' ]);
	</script>
<noscript><img src="https://pixel.wp.com/b.gif?v=noscript" style="height:1px;width:1px;overflow:hidden;position:absolute;bottom:1px;" alt="" /></noscript>
<script>
if ( 'object' === typeof wpcom_mobile_user_agent_info ) {

	wpcom_mobile_user_agent_info.init();
	var mobileStatsQueryString = "";
	
	if( false !== wpcom_mobile_user_agent_info.matchedPlatformName )
		mobileStatsQueryString += "&x_" + 'mobile_platforms' + '=' + wpcom_mobile_user_agent_info.matchedPlatformName;
	
	if( false !== wpcom_mobile_user_agent_info.matchedUserAgentName )
		mobileStatsQueryString += "&x_" + 'mobile_devices' + '=' + wpcom_mobile_user_agent_info.matchedUserAgentName;
	
	if( wpcom_mobile_user_agent_info.isIPad() )
		mobileStatsQueryString += "&x_" + 'ipad_views' + '=' + 'views';

	if( "" != mobileStatsQueryString ) {
		new Image().src = document.location.protocol + '//pixel.wp.com/g.gif?v=wpcom-no-pv' + mobileStatsQueryString + '&baba=' + Math.random();
	}
	
}
</script>
<style>img#wpstats {
			position: absolute !important;
			clip: rect(0, 0, 0, 0);
			padding: 0 !important;
			border: 0 !important;
			height: 0 !important;
			width: 0 !important;
			overflow: hidden;
		}</style><img src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/g.gif" alt=":)" id="wpstats"><iframe src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/saved_resource.html" style="display: none;"></iframe><div id="sharing_email" style="display: none;">
		<form action="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/" method="post">
			<label for="target_email">Send to Email Address</label>
			<input type="email" name="target_email" id="target_email" value="">

			
				<label for="source_name">Your Name</label>
				<input type="text" name="source_name" id="source_name" value="">

				<label for="source_email">Your Email Address</label>
				<input type="email" name="source_email" id="source_email" value="">

						<input type="text" id="jetpack-source_f_name" name="source_f_name" class="input" value="" size="25" autocomplete="off" title="This field is for validation and should not be changed">
			
			<div class="g-recaptcha" data-sitekey="6LcmyE0UAAAAALID28yVNg7pFCodGaArJzHitez_" data-theme="light" data-type="image" data-tabindex="0" data-lazy="true" data-url="https://www.google.com/recaptcha/api.js?hl=en"></div>
			
			<img style="float: right; display: none" class="loading" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/loading.gif" alt="loading" width="16" height="16" scale="0">
			<input type="submit" value="Send Email" class="sharing_send">
			<a rel="nofollow" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/#cancel" class="sharing_cancel" role="button">Cancel</a>

			<div class="errors errors-1" style="display: none;">
				Post was not sent - check your email addresses!			</div>

			<div class="errors errors-2" style="display: none;">
				Email check failed, please try again			</div>

			<div class="errors errors-3" style="display: none;">
				Sorry, your blog cannot share posts by email.			</div>
		</form>
	</div><iframe scrolling="no" id="wpcom_remote_login_key" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/remote-login.html" style="display: none;"></iframe><script src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/actionbar.js" defer=""></script><div id="actionbar" class="actnbr-pub-twentytwelve actnbr-has-follow actnbr-hidden"><ul><li class="actnbr-btn actnbr-hidden"> 				<a class="actnbr-action actnbr-actn-follow" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/"><svg class="gridicon gridicon__follow" height="24px" width="24px" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 16v2h-3v3h-2v-3h-3v-2h3v-3h2v3h3zM20 2v9h-4v3h-3v4H4c-1.1 0-2-.9-2-2V2h18zM8 13v-1H4v1h4zm3-3H4v1h7v-1zm0-2H4v1h7V8zm7-4H4v2h14V4z"></path></g></svg><span>Follow</span></a><a class="actnbr-action actnbr-actn-following no-display" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/"><svg class="gridicon gridicon__following" height="24px" width="24px" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 13.482L15.508 21 12 17.4l1.412-1.388 2.106 2.188 6.094-6.094L23 13.482zm-7.455 1.862L20 10.89V2H2v14c0 1.1.9 2 2 2h4.538l4.913-4.832 2.095 2.176zM8 13H4v-1h4v1zm3-2H4v-1h7v1zm0-2H4V8h7v1zm7-3H4V4h14v2z"></path></g></svg><span>Following</span></a> 				<div class="actnbr-popover tip tip-top-left actnbr-notice" id="follow-bubble"> 					<div class="tip-arrow"></div> 					<div class="tip-inner actnbr-follow-bubble"> 				<ul> 					<li class="actnbr-sitename actnbr-hidden"><a href="https://blog.smittytone.net/"><img alt="" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/cropped-rassilonblackwhite.png" class="avatar avatar-50" height="50" width="50" srcset="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=50&amp;zoom=2 2x" scale="2"> smittytone messes with micros</a></li> 					<form> 					<li class="actnbr-login-nudge actnbr-hidden"><div>Already have a WordPress.com account? <a href="https://wordpress.com/log-in?redirect_to=https%3A%2F%2Fr-login.wordpress.com%2Fremote-login.php%3Faction%3Dlink%26back%3Dhttps%253A%252F%252Fblog.smittytone.net%252F2021%252F02%252F02%252Fprogram-raspberry-pi-pico-c-mac%252F">Log in now.</a></div></li> 				</form></ul> 			</div> 				</div> 					</li><li class="actnbr-ellipsis actnbr-hidden"> 				<svg class="gridicon gridicon__ellipsis" height="24" width="24" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><circle cx="5" cy="12" r="2"></circle><circle cx="19" cy="12" r="2"></circle><circle cx="12" cy="12" r="2"></circle></g></svg> 				<div class="actnbr-popover tip tip-top-left actnbr-more"> 				<div class="tip-arrow"></div> 				<div class="tip-inner"> 					<ul> 						<li class="actnbr-sitename actnbr-hidden"><a href="https://blog.smittytone.net/"><img alt="" src="./How to program the Raspberry Pi Pico in C on a Mac _ smittytone messes with micros_files/cropped-rassilonblackwhite.png" class="avatar avatar-50" height="50" width="50" srcset="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=50&amp;zoom=2 2x" scale="2"> smittytone messes with micros</a></li> 					<li class="actnbr-folded-customize actnbr-hidden"><a href="https://smittytone.wordpress.com/wp-admin/customize.php?url=https%3A%2F%2Fsmittytone.wordpress.com%2F2021%2F02%2F02%2Fprogram-raspberry-pi-pico-c-mac%2F"><svg class="gridicon gridicon__customize" height="20px" width="20px" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M2 6c0-1.505.78-3.08 2-4 0 .845.69 2 2 2 1.657 0 3 1.343 3 3 0 .386-.08.752-.212 1.09.74.594 1.476 1.19 2.19 1.81L8.9 11.98c-.62-.716-1.214-1.454-1.807-2.192C6.753 9.92 6.387 10 6 10c-2.21 0-4-1.79-4-4zm12.152 6.848l1.34-1.34c.607.304 1.283.492 2.008.492 2.485 0 4.5-2.015 4.5-4.5 0-.725-.188-1.4-.493-2.007L18 9l-2-2 3.507-3.507C18.9 3.188 18.225 3 17.5 3 15.015 3 13 5.015 13 7.5c0 .725.188 1.4.493 2.007L3 20l2 2 6.848-6.848c1.885 1.928 3.874 3.753 5.977 5.45l1.425 1.148 1.5-1.5-1.15-1.425c-1.695-2.103-3.52-4.092-5.448-5.977z" data-reactid=".2.1.1:0.1b.0"></path></g></svg><span>Customize<span></span></span></a></li> 						<li class="actnbr-folded-follow actnbr-hidden"><a class="actnbr-action actnbr-actn-follow" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/"><svg class="gridicon gridicon__follow" height="24px" width="24px" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 16v2h-3v3h-2v-3h-3v-2h3v-3h2v3h3zM20 2v9h-4v3h-3v4H4c-1.1 0-2-.9-2-2V2h18zM8 13v-1H4v1h4zm3-3H4v1h7v-1zm0-2H4v1h7V8zm7-4H4v2h14V4z"></path></g></svg><span>Follow</span></a><a class="actnbr-action actnbr-actn-following no-display" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/"><svg class="gridicon gridicon__following" height="24px" width="24px" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 13.482L15.508 21 12 17.4l1.412-1.388 2.106 2.188 6.094-6.094L23 13.482zm-7.455 1.862L20 10.89V2H2v14c0 1.1.9 2 2 2h4.538l4.913-4.832 2.095 2.176zM8 13H4v-1h4v1zm3-2H4v-1h7v1zm0-2H4V8h7v1zm7-3H4V4h14v2z"></path></g></svg><span>Following</span></a></li> 					<li class="actnbr-signup actnbr-hidden"><a href="https://wordpress.com/start/">Sign up</a></li> 						<li class="actnbr-login actnbr-hidden"><a href="https://wordpress.com/log-in?redirect_to=https%3A%2F%2Fr-login.wordpress.com%2Fremote-login.php%3Faction%3Dlink%26back%3Dhttps%253A%252F%252Fblog.smittytone.net%252F2021%252F02%252F02%252Fprogram-raspberry-pi-pico-c-mac%252F">Log in</a></li> 						 						<li class="actnbr-shortlink actnbr-hidden"><a href="https://wp.me/pKqFg-zS">Copy shortlink</a></li> 						<li class="flb-report actnbr-hidden"><a href="http://en.wordpress.com/abuse/">Report this content</a></li> 						 						 						<li class="actnbr-subs actnbr-hidden"><a href="https://subscribe.wordpress.com/">Manage subscriptions</a></li> 						<li class="actnbr-fold actnbr-hidden"><a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/">Collapse this bar</a></li> 						</ul> 					</div> 					</div> 				</li> 				</ul></div></body></html>
  
  
  Debugging setup
  
  
  
<!DOCTYPE html>
<!-- saved from url=(0087)https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/ -->
<html lang="en" class="wf-oswald-n4-active wf-active"><!--<![endif]--><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

<meta name="viewport" content="width=device-width">
<title>How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico | smittytone messes with micros</title>
<link rel="profile" href="https://gmpg.org/xfn/11">
<link rel="pingback" href="https://blog.smittytone.net/xmlrpc.php">
<!--[if lt IE 9]>
<script src="https://s0.wp.com/wp-content/themes/pub/twentytwelve/js/html5.js?ver=3.7.0" type="text/javascript"></script>
<![endif]-->
<script type="text/javascript" async="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/platform.js"></script><script type="text/javascript" async="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/platform.js"></script><script src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/webfont.js" type="text/javascript" async=""></script><script type="text/javascript">
  WebFontConfig = {"google":{"families":["Oswald:r:latin,latin-ext"]}};
  (function() {
    var wf = document.createElement('script');
    wf.src = 'https://s0.wp.com/wp-content/plugins/custom-fonts/js/webfont.js';
    wf.type = 'text/javascript';
    wf.async = 'true';
    var s = document.getElementsByTagName('script')[0];
    s.parentNode.insertBefore(wf, s);
	})();
</script><style id="jetpack-custom-fonts-css">.wf-active .site-header h1{font-size:33.8px;font-family:"Oswald",sans-serif;font-style:normal;font-weight:400}.wf-active h1, .wf-active h2, .wf-active h3, .wf-active h4, .wf-active h5, .wf-active h6{font-family:"Oswald",sans-serif;font-style:normal;font-weight:400}.wf-active .entry-header .entry-title{font-size:26px;font-weight:400;font-style:normal}.wf-active .comment-content h1, .wf-active .entry-content h1{font-size:27.3px;font-style:normal;font-weight:400}.wf-active .comment-content h2, .wf-active .entry-content h2{font-size:23.4px;font-style:normal;font-weight:400}.wf-active .comment-content h3, .wf-active .entry-content h3{font-size:20.8px;font-style:normal;font-weight:400}.wf-active .comment-content h4, .wf-active .entry-content h4{font-size:18.2px;font-style:normal;font-weight:400}.wf-active .comment-content h5, .wf-active .entry-content h5{font-size:16.9px;font-style:normal;font-weight:400}.wf-active .comment-content h6, .wf-active .entry-content h6{font-size:15.6px;font-style:normal;font-weight:400}.wf-active article.format-image footer h1{font-size:16.9px;font-weight:400;font-style:normal}.wf-active article.format-image footer h2{font-size:14.3px;font-style:normal;font-weight:400}.wf-active article.format-link header{font-size:14.3px;font-weight:400;font-style:normal}.wf-active .comments-title{font-size:20.8px;font-weight:400;font-style:normal}.wf-active .comments-area article header h4{font-size:15.6px;font-weight:400;font-style:normal}.wf-active #respond h3#reply-title{font-size:20.8px;font-style:normal;font-weight:400}.wf-active .entry-header .entry-title{font-size:28.6px;font-style:normal;font-weight:400}</style>
<meta name="robots" content="max-image-preview:large">

<!-- Async WordPress.com Remote Login -->
<script id="wpcom_remote_login_js">
var wpcom_remote_login_extra_auth = '';
function wpcom_remote_login_remove_dom_node_id( element_id ) {
	var dom_node = document.getElementById( element_id );
	if ( dom_node ) { dom_node.parentNode.removeChild( dom_node ); }
}
function wpcom_remote_login_remove_dom_node_classes( class_name ) {
	var dom_nodes = document.querySelectorAll( '.' + class_name );
	for ( var i = 0; i < dom_nodes.length; i++ ) {
		dom_nodes[ i ].parentNode.removeChild( dom_nodes[ i ] );
	}
}
function wpcom_remote_login_final_cleanup() {
	wpcom_remote_login_remove_dom_node_classes( "wpcom_remote_login_msg" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_key" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_validate" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_js" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_request_access_iframe" );
	wpcom_remote_login_remove_dom_node_id( "wpcom_request_access_styles" );
}

// Watch for messages back from the remote login
window.addEventListener( "message", function( e ) {
	if ( e.origin === "https://r-login.wordpress.com" ) {
		var data = {};
		try {
			data = JSON.parse( e.data );
		} catch( e ) {
			wpcom_remote_login_final_cleanup();
			return;
		}

		if ( data.msg === 'LOGIN' ) {
			// Clean up the login check iframe
			wpcom_remote_login_remove_dom_node_id( "wpcom_remote_login_key" );

			var id_regex = new RegExp( /^[0-9]+$/ );
			var token_regex = new RegExp( /^.*|.*|.*$/ );
			if (
				token_regex.test( data.token )
				&& id_regex.test( data.wpcomid )
			) {
				// We have everything we need to ask for a login
				var script = document.createElement( "script" );
				script.setAttribute( "id", "wpcom_remote_login_validate" );
				script.src = '/remote-login.php?wpcom_remote_login=validate'
					+ '&wpcomid=' + data.wpcomid
					+ '&token=' + encodeURIComponent( data.token )
					+ '&host=' + window.location.protocol
					+ '//' + window.location.hostname
					+ '&postid=2258'
					+ '&is_singular=1';
				document.body.appendChild( script );
			}

			return;
		}

		// Safari ITP, not logged in, so redirect
		if ( data.msg === 'LOGIN-REDIRECT' ) {
			window.location = 'https://wordpress.com/log-in?redirect_to=' + window.location.href;
			return;
		}

		// Safari ITP, storage access failed, remove the request
		if ( data.msg === 'LOGIN-REMOVE' ) {
			var css_zap = 'html { -webkit-transition: margin-top 1s; transition: margin-top 1s; } /* 9001 */ html { margin-top: 0 !important; } * html body { margin-top: 0 !important; } @media screen and ( max-width: 782px ) { html { margin-top: 0 !important; } * html body { margin-top: 0 !important; } }';
			var style_zap = document.createElement( 'style' );
			style_zap.type = 'text/css';
			style_zap.appendChild( document.createTextNode( css_zap ) );
			document.body.appendChild( style_zap );

			var e = document.getElementById( 'wpcom_request_access_iframe' );
			e.parentNode.removeChild( e );

			document.cookie = 'wordpress_com_login_access=denied; path=/; max-age=31536000';

			return;
		}

		// Safari ITP
		if ( data.msg === 'REQUEST_ACCESS' ) {
			console.log( 'request access: safari' );

			// Check ITP iframe enable/disable knob
			if ( wpcom_remote_login_extra_auth !== 'safari_itp_iframe' ) {
				return;
			}

			// If we are in a "private window" there is no ITP.
			var private_window = false;
			try {
				var opendb = window.openDatabase( null, null, null, null );
			} catch( e ) {
				private_window = true;
			}

			if ( private_window ) {
				console.log( 'private window' );
				return;
			}

			var iframe = document.createElement( 'iframe' );
			iframe.id = 'wpcom_request_access_iframe';
			iframe.setAttribute( 'scrolling', 'no' );
			iframe.setAttribute( 'sandbox', 'allow-storage-access-by-user-activation allow-scripts allow-same-origin allow-top-navigation-by-user-activation' );
			iframe.src = 'https://r-login.wordpress.com/remote-login.php?wpcom_remote_login=request_access&origin=' + encodeURIComponent( data.origin ) + '&wpcomid=' + encodeURIComponent( data.wpcomid );

			var css = 'html { -webkit-transition: margin-top 1s; transition: margin-top 1s; } /* 9001 */ html { margin-top: 46px !important; } * html body { margin-top: 46px !important; } @media screen and ( max-width: 660px ) { html { margin-top: 71px !important; } * html body { margin-top: 71px !important; } #wpcom_request_access_iframe { display: block; height: 71px !important; } } #wpcom_request_access_iframe { border: 0px; height: 46px; position: fixed; top: 0; left: 0; width: 100%; min-width: 100%; z-index: 99999; background: #23282d; } ';

			var style = document.createElement( 'style' );
			style.type = 'text/css';
			style.id = 'wpcom_request_access_styles';
			style.appendChild( document.createTextNode( css ) );
			document.body.appendChild( style );

			document.body.appendChild( iframe );
		}

		if ( data.msg === 'DONE' ) {
			wpcom_remote_login_final_cleanup();
		}
	}
}, false );

// Inject the remote login iframe after the page has had a chance to load
// more critical resources
window.addEventListener( "DOMContentLoaded", function( e ) {
	var iframe = document.createElement( "iframe" );
	iframe.style.display = "none";
	iframe.setAttribute( "scrolling", "no" );
	iframe.setAttribute( "id", "wpcom_remote_login_key" );
	iframe.src = "https://r-login.wordpress.com/remote-login.php"
		+ "?wpcom_remote_login=key"
		+ "&origin=aHR0cHM6Ly9ibG9nLnNtaXR0eXRvbmUubmV0"
		+ "&wpcomid=11065590"
		+ "&time=1636164050";
	document.body.appendChild( iframe );
}, false );
</script>
<link rel="dns-prefetch" href="https://s0.wp.com/">
<link rel="dns-prefetch" href="https://smittytone.wordpress.com/">
<link rel="dns-prefetch" href="https://fonts.googleapis.com/">
<link href="https://fonts.gstatic.com/" crossorigin="" rel="preconnect">
<link rel="alternate" type="application/rss+xml" title="smittytone messes with micros » Feed" href="https://blog.smittytone.net/feed/">
<link rel="alternate" type="application/rss+xml" title="smittytone messes with micros » Comments Feed" href="https://blog.smittytone.net/comments/feed/">
<link rel="alternate" type="application/rss+xml" title="smittytone messes with micros » How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico Comments Feed" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/feed/">
	<script type="text/javascript">
		/* <![CDATA[ */
		function addLoadEvent(func) {
			var oldonload = window.onload;
			if (typeof window.onload != 'function') {
				window.onload = func;
			} else {
				window.onload = function () {
					oldonload();
					func();
				}
			}
		}
		/* ]]> */
	</script>
			<script type="text/javascript">
			window._wpemojiSettings = {"baseUrl":"https:\/\/s0.wp.com\/wp-content\/mu-plugins\/wpcom-smileys\/twemoji\/2\/72x72\/","ext":".png","svgUrl":"https:\/\/s0.wp.com\/wp-content\/mu-plugins\/wpcom-smileys\/twemoji\/2\/svg\/","svgExt":".svg","source":{"concatemoji":"https:\/\/s0.wp.com\/wp-includes\/js\/wp-emoji-release.min.js?m=1625065786h&ver=5.8.1"}};
			!function(e,a,t){var n,r,o,i=a.createElement("canvas"),p=i.getContext&&i.getContext("2d");function s(e,t){var a=String.fromCharCode;p.clearRect(0,0,i.width,i.height),p.fillText(a.apply(this,e),0,0);e=i.toDataURL();return p.clearRect(0,0,i.width,i.height),p.fillText(a.apply(this,t),0,0),e===i.toDataURL()}function c(e){var t=a.createElement("script");t.src=e,t.defer=t.type="text/javascript",a.getElementsByTagName("head")[0].appendChild(t)}for(o=Array("flag","emoji"),t.supports={everything:!0,everythingExceptFlag:!0},r=0;r<o.length;r++)t.supports[o[r]]=function(e){if(!p||!p.fillText)return!1;switch(p.textBaseline="top",p.font="600 32px Arial",e){case"flag":return s([127987,65039,8205,9895,65039],[127987,65039,8203,9895,65039])?!1:!s([55356,56826,55356,56819],[55356,56826,8203,55356,56819])&&!s([55356,57332,56128,56423,56128,56418,56128,56421,56128,56430,56128,56423,56128,56447],[55356,57332,8203,56128,56423,8203,56128,56418,8203,56128,56421,8203,56128,56430,8203,56128,56423,8203,56128,56447]);case"emoji":return!s([10084,65039,8205,55357,56613],[10084,65039,8203,55357,56613])}return!1}(o[r]),t.supports.everything=t.supports.everything&&t.supports[o[r]],"flag"!==o[r]&&(t.supports.everythingExceptFlag=t.supports.everythingExceptFlag&&t.supports[o[r]]);t.supports.everythingExceptFlag=t.supports.everythingExceptFlag&&!t.supports.flag,t.DOMReady=!1,t.readyCallback=function(){t.DOMReady=!0},t.supports.everything||(n=function(){t.readyCallback()},a.addEventListener?(a.addEventListener("DOMContentLoaded",n,!1),e.addEventListener("load",n,!1)):(e.attachEvent("onload",n),a.attachEvent("onreadystatechange",function(){"complete"===a.readyState&&t.readyCallback()})),(n=t.source||{}).concatemoji?c(n.concatemoji):n.wpemoji&&n.twemoji&&(c(n.twemoji),c(n.wpemoji)))}(window,document,window._wpemojiSettings);
		</script><script src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/wp-emoji-release.min.js" type="text/javascript" defer=""></script>
		<style type="text/css">
img.wp-smiley,
img.emoji {
	display: inline !important;
	border: none !important;
	box-shadow: none !important;
	height: 1em !important;
	width: 1em !important;
	margin: 0 .07em !important;
	vertical-align: -0.1em !important;
	background: none !important;
	padding: 0 !important;
}
</style>
	<link rel="stylesheet" id="all-css-0-1" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource" type="text/css" media="all">
<style id="wp-block-library-inline-css">
.has-text-align-justify {
	text-align:justify;
}
</style>
<style id="global-styles-inline-css">
body{--wp--preset--color--black: #000000;--wp--preset--color--cyan-bluish-gray: #abb8c3;--wp--preset--color--white: #ffffff;--wp--preset--color--pale-pink: #f78da7;--wp--preset--color--vivid-red: #cf2e2e;--wp--preset--color--luminous-vivid-orange: #ff6900;--wp--preset--color--luminous-vivid-amber: #fcb900;--wp--preset--color--light-green-cyan: #7bdcb5;--wp--preset--color--vivid-green-cyan: #00d084;--wp--preset--color--pale-cyan-blue: #8ed1fc;--wp--preset--color--vivid-cyan-blue: #0693e3;--wp--preset--color--vivid-purple: #9b51e0;--wp--preset--gradient--vivid-cyan-blue-to-vivid-purple: linear-gradient(135deg,rgba(6,147,227,1) 0%,rgb(155,81,224) 100%);--wp--preset--gradient--light-green-cyan-to-vivid-green-cyan: linear-gradient(135deg,rgb(122,220,180) 0%,rgb(0,208,130) 100%);--wp--preset--gradient--luminous-vivid-amber-to-luminous-vivid-orange: linear-gradient(135deg,rgba(252,185,0,1) 0%,rgba(255,105,0,1) 100%);--wp--preset--gradient--luminous-vivid-orange-to-vivid-red: linear-gradient(135deg,rgba(255,105,0,1) 0%,rgb(207,46,46) 100%);--wp--preset--gradient--very-light-gray-to-cyan-bluish-gray: linear-gradient(135deg,rgb(238,238,238) 0%,rgb(169,184,195) 100%);--wp--preset--gradient--cool-to-warm-spectrum: linear-gradient(135deg,rgb(74,234,220) 0%,rgb(151,120,209) 20%,rgb(207,42,186) 40%,rgb(238,44,130) 60%,rgb(251,105,98) 80%,rgb(254,248,76) 100%);--wp--preset--gradient--blush-light-purple: linear-gradient(135deg,rgb(255,206,236) 0%,rgb(152,150,240) 100%);--wp--preset--gradient--blush-bordeaux: linear-gradient(135deg,rgb(254,205,165) 0%,rgb(254,45,45) 50%,rgb(107,0,62) 100%);--wp--preset--gradient--luminous-dusk: linear-gradient(135deg,rgb(255,203,112) 0%,rgb(199,81,192) 50%,rgb(65,88,208) 100%);--wp--preset--gradient--pale-ocean: linear-gradient(135deg,rgb(255,245,203) 0%,rgb(182,227,212) 50%,rgb(51,167,181) 100%);--wp--preset--gradient--electric-grass: linear-gradient(135deg,rgb(202,248,128) 0%,rgb(113,206,126) 100%);--wp--preset--gradient--midnight: linear-gradient(135deg,rgb(2,3,129) 0%,rgb(40,116,252) 100%);--wp--preset--duotone--dark-grayscale: url('#wp-duotone-dark-grayscale');--wp--preset--duotone--grayscale: url('#wp-duotone-grayscale');--wp--preset--duotone--purple-yellow: url('#wp-duotone-purple-yellow');--wp--preset--duotone--blue-red: url('#wp-duotone-blue-red');--wp--preset--duotone--midnight: url('#wp-duotone-midnight');--wp--preset--duotone--magenta-yellow: url('#wp-duotone-magenta-yellow');--wp--preset--duotone--purple-green: url('#wp-duotone-purple-green');--wp--preset--duotone--blue-orange: url('#wp-duotone-blue-orange');--wp--preset--font-size--small: 13px;--wp--preset--font-size--normal: 16px;--wp--preset--font-size--medium: 20px;--wp--preset--font-size--large: 36px;--wp--preset--font-size--huge: 42px;}.has-black-color{color: var(--wp--preset--color--black) !important;}.has-cyan-bluish-gray-color{color: var(--wp--preset--color--cyan-bluish-gray) !important;}.has-white-color{color: var(--wp--preset--color--white) !important;}.has-pale-pink-color{color: var(--wp--preset--color--pale-pink) !important;}.has-vivid-red-color{color: var(--wp--preset--color--vivid-red) !important;}.has-luminous-vivid-orange-color{color: var(--wp--preset--color--luminous-vivid-orange) !important;}.has-luminous-vivid-amber-color{color: var(--wp--preset--color--luminous-vivid-amber) !important;}.has-light-green-cyan-color{color: var(--wp--preset--color--light-green-cyan) !important;}.has-vivid-green-cyan-color{color: var(--wp--preset--color--vivid-green-cyan) !important;}.has-pale-cyan-blue-color{color: var(--wp--preset--color--pale-cyan-blue) !important;}.has-vivid-cyan-blue-color{color: var(--wp--preset--color--vivid-cyan-blue) !important;}.has-vivid-purple-color{color: var(--wp--preset--color--vivid-purple) !important;}.has-black-background-color{background-color: var(--wp--preset--color--black) !important;}.has-cyan-bluish-gray-background-color{background-color: var(--wp--preset--color--cyan-bluish-gray) !important;}.has-white-background-color{background-color: var(--wp--preset--color--white) !important;}.has-pale-pink-background-color{background-color: var(--wp--preset--color--pale-pink) !important;}.has-vivid-red-background-color{background-color: var(--wp--preset--color--vivid-red) !important;}.has-luminous-vivid-orange-background-color{background-color: var(--wp--preset--color--luminous-vivid-orange) !important;}.has-luminous-vivid-amber-background-color{background-color: var(--wp--preset--color--luminous-vivid-amber) !important;}.has-light-green-cyan-background-color{background-color: var(--wp--preset--color--light-green-cyan) !important;}.has-vivid-green-cyan-background-color{background-color: var(--wp--preset--color--vivid-green-cyan) !important;}.has-pale-cyan-blue-background-color{background-color: var(--wp--preset--color--pale-cyan-blue) !important;}.has-vivid-cyan-blue-background-color{background-color: var(--wp--preset--color--vivid-cyan-blue) !important;}.has-vivid-purple-background-color{background-color: var(--wp--preset--color--vivid-purple) !important;}.has-black-border-color{border-color: var(--wp--preset--color--black) !important;}.has-cyan-bluish-gray-border-color{border-color: var(--wp--preset--color--cyan-bluish-gray) !important;}.has-white-border-color{border-color: var(--wp--preset--color--white) !important;}.has-pale-pink-border-color{border-color: var(--wp--preset--color--pale-pink) !important;}.has-vivid-red-border-color{border-color: var(--wp--preset--color--vivid-red) !important;}.has-luminous-vivid-orange-border-color{border-color: var(--wp--preset--color--luminous-vivid-orange) !important;}.has-luminous-vivid-amber-border-color{border-color: var(--wp--preset--color--luminous-vivid-amber) !important;}.has-light-green-cyan-border-color{border-color: var(--wp--preset--color--light-green-cyan) !important;}.has-vivid-green-cyan-border-color{border-color: var(--wp--preset--color--vivid-green-cyan) !important;}.has-pale-cyan-blue-border-color{border-color: var(--wp--preset--color--pale-cyan-blue) !important;}.has-vivid-cyan-blue-border-color{border-color: var(--wp--preset--color--vivid-cyan-blue) !important;}.has-vivid-purple-border-color{border-color: var(--wp--preset--color--vivid-purple) !important;}.has-vivid-cyan-blue-to-vivid-purple-gradient-background{background: var(--wp--preset--gradient--vivid-cyan-blue-to-vivid-purple) !important;}.has-light-green-cyan-to-vivid-green-cyan-gradient-background{background: var(--wp--preset--gradient--light-green-cyan-to-vivid-green-cyan) !important;}.has-luminous-vivid-amber-to-luminous-vivid-orange-gradient-background{background: var(--wp--preset--gradient--luminous-vivid-amber-to-luminous-vivid-orange) !important;}.has-luminous-vivid-orange-to-vivid-red-gradient-background{background: var(--wp--preset--gradient--luminous-vivid-orange-to-vivid-red) !important;}.has-very-light-gray-to-cyan-bluish-gray-gradient-background{background: var(--wp--preset--gradient--very-light-gray-to-cyan-bluish-gray) !important;}.has-cool-to-warm-spectrum-gradient-background{background: var(--wp--preset--gradient--cool-to-warm-spectrum) !important;}.has-blush-light-purple-gradient-background{background: var(--wp--preset--gradient--blush-light-purple) !important;}.has-blush-bordeaux-gradient-background{background: var(--wp--preset--gradient--blush-bordeaux) !important;}.has-luminous-dusk-gradient-background{background: var(--wp--preset--gradient--luminous-dusk) !important;}.has-pale-ocean-gradient-background{background: var(--wp--preset--gradient--pale-ocean) !important;}.has-electric-grass-gradient-background{background: var(--wp--preset--gradient--electric-grass) !important;}.has-midnight-gradient-background{background: var(--wp--preset--gradient--midnight) !important;}.has-small-font-size{font-size: var(--wp--preset--font-size--small) !important;}.has-normal-font-size{font-size: var(--wp--preset--font-size--normal) !important;}.has-medium-font-size{font-size: var(--wp--preset--font-size--medium) !important;}.has-large-font-size{font-size: var(--wp--preset--font-size--large) !important;}.has-huge-font-size{font-size: var(--wp--preset--font-size--huge) !important;}
</style>
<link crossorigin="anonymous" rel="stylesheet" id="twentytwelve-fonts-css" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/css" media="all">
<link rel="stylesheet" id="all-css-4-1" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(1)" type="text/css" media="all">
<!--[if lt IE 9]>
<link rel='stylesheet' id='twentytwelve-ie-css'  href='https://s0.wp.com/wp-content/themes/pub/twentytwelve/css/ie.css?m=1423935238h&#038;ver=20150214' media='all' />
<![endif]-->
<link rel="stylesheet" id="all-css-6-1" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(2)" type="text/css" media="all">
<style id="jetpack-global-styles-frontend-style-inline-css">
:root { --font-headings: unset; --font-base: unset; --font-headings-default: -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Oxygen-Sans,Ubuntu,Cantarell,"Helvetica Neue",sans-serif; --font-base-default: -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Oxygen-Sans,Ubuntu,Cantarell,"Helvetica Neue",sans-serif;}
</style>
<link rel="stylesheet" id="all-css-8-1" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(3)" type="text/css" media="all">
<script id="jetpack_related-posts-js-extra">
var related_posts_js_options = {"post_heading":"h4"};
</script>
<script id="wpcom-actionbar-placeholder-js-extra">
var actionbardata = {"siteID":"11065590","siteURL":"https:\/\/blog.smittytone.net","xhrURL":"https:\/\/blog.smittytone.net\/wp-admin\/admin-ajax.php","nonce":"596ee1a7a9","isLoggedIn":"","statusMessage":"","subsEmailDefault":"instantly","proxyScriptUrl":"https:\/\/s0.wp.com\/wp-content\/js\/wpcom-proxy-request.js?ver=20211021","shortlink":"https:\/\/wp.me\/pKqFg-Aq","i18n":{"followedText":"New posts from this site will now appear in your <a href=\"https:\/\/wordpress.com\/read\">Reader<\/a>","foldBar":"Collapse this bar","unfoldBar":"Expand this bar"}};
</script>
<script crossorigin="anonymous" type="text/javascript" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(4)"></script>
<script type="text/javascript">
	window.addEventListener( 'DOMContentLoaded', function() {
		rltInitialize( {"token":null,"iframeOrigins":["https:\/\/widgets.wp.com"]} );
	} );
</script>
<link rel="EditURI" type="application/rsd+xml" title="RSD" href="https://smittytone.wordpress.com/xmlrpc.php?rsd">
<link rel="wlwmanifest" type="application/wlwmanifest+xml" href="https://s0.wp.com/wp-includes/wlwmanifest.xml"> 
<meta name="generator" content="WordPress.com">
<link rel="canonical" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
<link rel="shortlink" href="https://wp.me/pKqFg-Aq">
<link rel="alternate" type="application/json+oembed" href="https://public-api.wordpress.com/oembed/?format=json&amp;url=https%3A%2F%2Fblog.smittytone.net%2F2021%2F02%2F05%2Fhow-to-debug-a-raspberry-pi-pico-with-a-mac-swd%2F&amp;for=wpcom-auto-discovery"><link rel="alternate" type="application/xml+oembed" href="https://public-api.wordpress.com/oembed/?format=xml&amp;url=https%3A%2F%2Fblog.smittytone.net%2F2021%2F02%2F05%2Fhow-to-debug-a-raspberry-pi-pico-with-a-mac-swd%2F&amp;for=wpcom-auto-discovery">
<!-- Jetpack Open Graph Tags -->
<meta property="og:type" content="article">
<meta property="og:title" content="How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico">
<meta property="og:url" content="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
<meta property="og:description" content="When you’ve used Serial Wire Debug (SWD) to help you correct the C or C++ code running on your Raspberry Pi Pico, you’ll never want to go back to USB and the UF2 file system again. I don’t — no mor…">
<meta property="article:published_time" content="2021-02-05T08:10:48+00:00">
<meta property="article:modified_time" content="2021-09-03T06:34:36+00:00">
<meta property="og:site_name" content="smittytone messes with micros">
<meta property="og:image" content="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg">
<meta property="og:image:width" content="1120">
<meta property="og:image:height" content="514">
<meta property="og:image:alt" content="">
<meta property="og:locale" content="en_US">
<meta name="twitter:creator" content="@TechTonicBlog">
<meta name="twitter:site" content="@TechTonicBlog">
<meta name="twitter:text:title" content="How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico">
<meta name="twitter:image" content="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=640">
<meta name="twitter:card" content="summary_large_image">
<meta property="article:publisher" content="https://www.facebook.com/WordPresscom">

<!-- End Jetpack Open Graph Tags -->
<link rel="openid.server" href="https://blog.smittytone.net/?openidserver=1">
<link rel="openid.delegate" href="https://blog.smittytone.net/">
<link rel="search" type="application/opensearchdescription+xml" href="https://blog.smittytone.net/osd.xml" title="smittytone messes with micros">
<link rel="search" type="application/opensearchdescription+xml" href="https://s1.wp.com/opensearch.xml" title="WordPress.com">
<meta name="theme-color" content="#e6e6e6">
<meta name="application-name" content="smittytone messes with micros"><meta name="msapplication-window" content="width=device-width;height=device-height"><meta name="msapplication-tooltip" content="BULLETINS FROM THE TECHNOLOGY FRONT LINE — AND OCCASIONALLY BEHIND IT"><meta name="msapplication-task" content="name=Subscribe;action-uri=https://blog.smittytone.net/feed/;icon-uri=https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=16"><meta name="msapplication-task" content="name=Sign up for a free blog;action-uri=http://wordpress.com/signup/;icon-uri=https://s0.wp.com/i/favicon.ico"><meta name="msapplication-task" content="name=WordPress.com Support;action-uri=http://support.wordpress.com/;icon-uri=https://s0.wp.com/i/favicon.ico"><meta name="msapplication-task" content="name=WordPress.com Forums;action-uri=http://forums.wordpress.com/;icon-uri=https://s0.wp.com/i/favicon.ico"><meta name="description" content="When you’ve used Serial Wire Debug (SWD) to help you correct the C or C++ code running on your Raspberry Pi Pico, you’ll never want to go back to USB and the UF2 file system again. I don’t — no more messing about unplugging and re-plugging cables for me. The Raspberry Pi Pico is ready…">
	<style type="text/css" id="twentytwelve-header-css">
			.site-title,
		.site-description {
			position: absolute;
			clip: rect(1px 1px 1px 1px); /* IE7 */
			clip: rect(1px, 1px, 1px, 1px);
		}
		</style>
	<link rel="amphtml" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/amp/"><link rel="icon" href="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=32" sizes="32x32">
<link rel="icon" href="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=192" sizes="192x192">
<link rel="apple-touch-icon" href="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=180">
<meta name="msapplication-TileImage" content="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=270">
<script charset="utf-8" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/rate.php"></script><link rel="stylesheet" type="text/css" id="gravatar-card-css" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/hovercard.min.css"><link rel="stylesheet" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/css(1)" media="all"><link rel="stylesheet" type="text/css" id="gravatar-card-services-css" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/services.min.css"><style type="text/css" id="pd_popup_holder_style_1209223_post_2258">#pd_popup_holder_1209223_post_2258 { position:absolute; display:none; width:350px; height:auto; top:0px; left:0px; z-index:10000; border:solid 1px #CCC; background-color:white; padding:0px 15px;font-family:Arial,Sans;box-shadow: -10px 10px 20px rgba(0, 0, 0, .5);-webkit-box-shadow: 0px 0px 6px rgba(0, 0, 0, .25);-moz-box-shadow: 0px 0px 6px rgba(0, 0, 0, .25); }</style><link href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/actionbar.css" type="text/css" rel="stylesheet"></head>

<body class="post-template-default single single-post postid-2258 single-format-standard wp-custom-logo wp-embed-responsive customizer-styles-applied custom-font-enabled single-author highlander-enabled highlander-light">
<div id="page" class="hfeed site">
	<header id="masthead" class="site-header" role="banner">
				<hgroup>
			<h1 class="site-title"><a href="https://blog.smittytone.net/" title="smittytone messes with micros" rel="home">smittytone messes with micros</a></h1>
			<h2 class="site-description">BULLETINS FROM THE TECHNOLOGY FRONT LINE —&nbsp;AND OCCASIONALLY BEHIND IT</h2>
		</hgroup>

		<nav id="site-navigation" class="main-navigation" role="navigation">
			<button class="menu-toggle">Menu</button>
			<a class="assistive-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#content" title="Skip to content">Skip to content</a>
			<div class="menu-main-menu-container"><ul id="menu-main-menu" class="nav-menu"><li id="menu-item-612" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-home menu-item-has-children menu-item-612"><a href="https://blog.smittytone.net/">Home</a>
<ul class="sub-menu">
	<li id="menu-item-613" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-613"><a href="https://blog.smittytone.net/about/">About this Blog…</a></li>
</ul>
</li>
<li id="menu-item-1314" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-has-children menu-item-1314"><a href="https://blog.smittytone.net/category/mac/">Mac</a>
<ul class="sub-menu">
	<li id="menu-item-1543" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-1543"><a href="https://blog.smittytone.net/category/how-to-mac/">How To (Mac)</a></li>
	<li id="menu-item-1315" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-1315"><a href="https://blog.smittytone.net/category/programming/">Programming</a></li>
</ul>
</li>
<li id="menu-item-614" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-has-children menu-item-614"><a href="https://blog.smittytone.net/category/raspberry-pi/">Raspberry Pi</a>
<ul class="sub-menu">
	<li id="menu-item-1484" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-1484"><a href="https://blog.smittytone.net/pi-knowledgebase/">Raspberry Pi Knowledgebase</a></li>
	<li id="menu-item-1542" class="menu-item menu-item-type-taxonomy menu-item-object-category current-post-ancestor current-menu-parent current-post-parent menu-item-1542"><a href="https://blog.smittytone.net/category/how-to-pi/">How To (Pi)</a></li>
	<li id="menu-item-934" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-934"><a href="https://blog.smittytone.net/category/hacks/">Hacks</a></li>
</ul>
</li>
<li id="menu-item-2996" class="menu-item menu-item-type-taxonomy menu-item-object-post_tag menu-item-2996"><a href="https://blog.smittytone.net/tag/pico/">Pico</a></li>
<li id="menu-item-663" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-663"><a href="https://blog.smittytone.net/category/retro/">Retro</a></li>
</ul></div>		</nav><!-- #site-navigation -->

						<a href="https://blog.smittytone.net/"><img src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/slice.png" class="header-image" width="1924" height="200" alt="" scale="0"></a>
			</header><!-- #masthead -->

	<div id="main" class="wrapper">
	<div id="primary" class="site-content">
		<div id="content" role="main">

			
				
	<article id="post-2258" class="post-2258 post type-post status-publish format-standard hentry category-how-to-mac category-how-to-pi category-raspberry-pi tag-mac tag-macos tag-osx tag-pico tag-raspberry-pi tag-swd">
				<header class="entry-header">
			
						<h1 class="entry-title">How to debug a Raspberry Pi Pico with a Mac, SWD and… another&nbsp;Pico</h1>
								</header><!-- .entry-header -->

				<div class="entry-content">
			
<p>When you’ve used <a rel="noreferrer noopener" href="https://en.wikipedia.org/wiki/JTAG#Similar_interface_standards" target="_blank">Serial Wire Debug</a> (SWD) to help you correct the C or C++ code running on your <a rel="noreferrer noopener" href="https://www.raspberrypi.org/documentation/pico/getting-started/" target="_blank">Raspberry Pi Pico</a>, you’ll never want to <a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/">go back to USB</a> and the <a rel="noreferrer noopener" href="https://github.com/microsoft/uf2" target="_blank">UF2</a> file system again. I don’t — no more messing about unplugging and re-plugging cables for me.</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg"><img data-attachment-id="2240" data-permalink="https://blog.smittytone.net/pico-debug/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg" data-orig-size="1120,514" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="pico-debug" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=625" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug.jpg" alt="The Raspberry Pi Pico" class="wp-image-2240" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=1024 1024w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico-debug.jpg 1120w" sizes="(max-width: 1024px) 100vw, 1024px"></a><figcaption>The Raspberry Pi Pico is ready for Serial Wire Debugging</figcaption></figure></div>



<span id="more-2258"></span>



<p><strong>Note</strong> If you haven’t read <a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/">the previous article in this series</a>, you should check it out — it covers setting up the Pico C/C++ SDK and the ARM toolchain, both of which are pre-requisites for what follows.</p>



<p>SWD uses three pins: one for data, another for a clock signal and a third for ground. It’s an ARM-developed technology supported by many MCU designs based on ARM’s core architecture. Essentially, it’s used to program MCUs and to do on-chip debugging (OCD): to run the code under the control of a remote bug-hunting tool, allowing you to do really useful diagnostic stuff like pause the program mid-flow to check the state of your application.</p>



<p>The Pico breaks out its RP2040 chip’s SWD pins as <strong>DEBUG</strong>; just solder on some header pins. But how do you make use of it? And how do you do so a Mac?</p>



<p>With a great deal of difficulty, seemed the answer to the second question, at least at first. Not so, though, and we have the Raspberry Pi Foundation to thank — yet again — for that. It has produced <em>picoprobe</em>, a program that runs on the Pico itself and turns it into a pocket USB-to-SWD adaptor. It’s a two-Pico setup: you have one Pico on which you’ll run your code and a second one that operates as a bridge between debugger software running on your host machine and the target MCU, accessed through its SWD pins.</p>



<p>Yes, that means you have to sacrifice a Pico to the development process, but since <a rel="noreferrer noopener" href="https://shop.pimoroni.com/products/raspberry-pi-pico" target="_blank">it only cost you £3.60</a>, so what? And it’s not actually lost for good. <em>picoprobe</em> is installed in the usual way: by mounting the host device’s storage and dragging a <code>.UF2</code> file across. And if you can do it once, you can do it again with a different application when you’ve finished with <em>picoprobe</em>.</p>



<p>For me, there’s no Earthly reason not to devote a Pico to this role given the benefits: fully interactive on-chip debugging and no faffing around with USB cables.</p>



<h2 class="has-text-color" style="color:#4e65ae;">Build Yourself a Picoprobe</h2>



<p>So how do you set it up?</p>



<p>There’s some extra software required, so you’ll need to install that, plus a further <em>Visual Studio Code</em> extension so that you can run it all from this editor.</p>



<p>Here are the setup steps. As before, I’ll assume you’re storing everything in a directory whose path is <code>~/git</code> and your project is called <code>PicoTest</code>, but you can change either or both of those values.</p>



<h4>Build and install picoprobe</h4>



<ol><li>Launch <em>Terminal</em>.</li><li><code>cd ~/git</code></li><li><code>git clone https://github.com/raspberrypi/picoprobe.git</code></li><li><code>cd picoprobe</code></li><li><code>mkdir build</code></li><li><code>cd build</code></li><li><code>cmake ..</code></li><li><code>make -j4</code></li><li><code>open .</code></li><li>Mount the Pico: hold down <strong>BOOTSEL</strong> and connect to USB.</li><li>Drag the file <code>picoprobe.uf2</code> to the mounted Pico storage.</li><li><code>cd ~/git</code></li><li><code>rm -rf picoprobe</code> <em>(optional)</em></li></ol>



<h4>Build and install OpenOCD</h4>



<p><a href="http://openocd.org/" target="_blank" rel="noreferrer noopener">OpenOCD</a> is the host-side tool that enables on-chip debugging: it manages the communication between MCU and debugger in co-operation with <em>picoprobe</em> on the Pico.</p>



<p><strong>Note</strong> You may already have some of the command line tools installed with <em>brew</em>. Don’t worry, <em>brew</em> will upgrade them if necessary.</p>



<ol><li><code>brew install libtool automake texinfo wget gcc pkg-config libusb</code></li><li><code>export PATH="/usr/local/opt/texinfo/bin:$PATH"</code></li><li><code>git clone https://github.com/raspberrypi/openocd.git \</code><br>  &nbsp;&nbsp;<code>--branch picoprobe --depth=1</code></li><li><code>cd openocd</code></li><li><code>./bootstrap</code></li><li><code>./configure --enable-picoprobe --disable-werror</code></li><li><code>make -j4</code></li><li><code>make install</code></li><li><code>cd ~/git</code></li><li><code>rm -rf openocd</code> <em>(optional)</em></li></ol>



<h4>Configure Visual Studio Code</h4>



<ol><li>Run <em>Visual Studio Code</em>.</li><li>Click on the <strong>Extensions</strong> icon in the left side toolbar.</li><li>Search for <code>cortex-debug</code> and install it. It’s the one by marus25. You only need install <em>Cortex-Debug</em>; you don’t need the device support extensions.</li></ol>



<h4>Configure Your Project</h4>



<ol><li>In Terminal, <code>cd ~/git/PicoTest</code></li><li>Paste <a href="https://gist.github.com/smittytone/81bac3ab9a78e21bd46ed20b0ba17d72">the following code</a> into a new file and save it to <code>~/git/PicoTest/.vscode/launch.json</code></li></ol>



<pre class="wp-block-preformatted">{
     "version": "0.2.0",
     "configurations": [
         {   "name": "Pico Debug",
             "device": "RP2040",
             "gdbPath": "arm-none-eabi-gdb",
             "cwd": "${workspaceRoot}",
             "executable": "${command:cmake.launchTargetPath}",
             "request": "launch",
             "type": "cortex-debug",
             "servertype": "openocd",
             "configFiles": [
                 "/interface/picoprobe.cfg",
                 "/target/rp2040.cfg"
             ],
             "svdFile": "${env:PICO_SDK_PATH}/src/rp2040/hardware_regs/rp2040.svd",
             "runToMain": true,
             "postRestartCommands": [
                 "break main",
                 "continue"
             ]
         }
     ]
 }</pre>



<h4 class="has-text-color" style="color:#4e65ae;">Wire up the Hardware</h4>



<p>Now for the hardware. Just connect the two Picos as shown below. The one with the USB cable, which you hook up to your Mac, is the programmer. You can power the target Pico from the <em>picoprobe</em> unit:</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png"><img data-attachment-id="2318" data-permalink="https://blog.smittytone.net/pico-debug-1/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png" data-orig-size="1400,1600" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-debug-1" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png?w=263" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png?w=625" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug-1.png" alt="" class="wp-image-2318" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png?w=896 896w, https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png?w=131 131w, https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png?w=263 263w, https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico-debug-1.png 1400w" sizes="(max-width: 896px) 100vw, 896px"></a><figcaption>Basic Picoprobe wiring (<strong>Note</strong> now corrected)</figcaption></figure></div>



<h2 class="has-text-color" style="color:#4e65ae;">Debug Your Project</h2>



<p><strong>Note</strong> If you’ve already built your code once, trash the existing <code>build</code> folder. This will save some toolchain confusion that might impede your progress when you run the debugger. You’ll probably have to choose your compiler (the ‘kit’) again: select <code>arm-none-eabi-gcc x.y.z</code>.</p>



<p>In <em>Visual Studio Code</em>, open your project folder. Hit <strong>Cmd</strong>–<strong>Shift</strong>–<strong>D</strong> or click <em>Visual Studio Code</em>’s <strong>Run</strong> icon in the left side toolbar. The debugger will open. It will ask you to specify your target — choose the <code>.elf</code> option that matches your project name.</p>



<p>Now click the green arrow next to <strong>Pico Debug</strong>. Your code will build, be transferred to the target and run:</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug.png"><img data-attachment-id="2270" data-permalink="https://blog.smittytone.net/pico-debug-2/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.png" data-orig-size="140,34" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-debug" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.png?w=140" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug.png?w=140" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug.png" alt="Visual Studio Code&#39;s Debug starter" class="wp-image-2270" width="140" height="34" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug.png?w=140&amp;zoom=2 2x" scale="2"></a><figcaption>Click to start debugging…</figcaption></figure></div>



<p>The debugger will then halt at the start of your program’s <code>main()</code> function. You control program flow using the play/pause, step over, step in, step out, restart and play buttons right at the top of <em>Visual Studio Code</em>: </p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug-controls.png"><img data-attachment-id="2273" data-permalink="https://blog.smittytone.net/pico-debug-controls/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-controls.png" data-orig-size="214,31" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-debug-controls" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-controls.png?w=214" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-controls.png?w=214" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug-controls.png" alt="The debug controls" class="wp-image-2273" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug-controls.png 214w, https://smittytone.files.wordpress.com/2021/02/pico-debug-controls.png?w=150 150w" sizes="(max-width: 214px) 100vw, 214px"></a><figcaption>The debug controls</figcaption></figure></div>



<p>You can set breakpoints by clicking to the left of the line number identifying a line of code:</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png"><img data-attachment-id="2275" data-permalink="https://blog.smittytone.net/pico-debug-breakpoint/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png" data-orig-size="800,220" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-debug-breakpoint" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png?w=625" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug-breakpoint.png" alt="Set breakpoints to pause your program and inspect its state" class="wp-image-2275" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png 800w, https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico-debug-breakpoint.png?w=768 768w" sizes="(max-width: 800px) 100vw, 800px"></a><figcaption>Set breakpoints to pause your program and inspect its state</figcaption></figure></div>



<p>The debugger will pause execution when it hits a breakpoint and display variables and their values in the left-hand column:</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png"><img data-attachment-id="2277" data-permalink="https://blog.smittytone.net/pico-debug-vars/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png" data-orig-size="300,500" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-debug-vars" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png?w=180" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png?w=300" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug-vars.png" alt="The debugger will show you your variables’ values" class="wp-image-2277" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png 300w, https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png?w=90 90w, https://smittytone.files.wordpress.com/2021/02/pico-debug-vars.png?w=180 180w" sizes="(max-width: 300px) 100vw, 300px"></a><figcaption>The debugger will show you your variables’ values</figcaption></figure></div>



<p>Step through the code line by line to see how these values change. At a function call, you can click the <strong>Step In</strong> button to jump into that function’s code, or click <strong>Step Over</strong> to run the function and stop again at the next line.</p>



<p>If you make some changes to your code, click the <strong>Stop</strong> button to stop debugging, and then click the green <strong>Pico Debug</strong> arrow again to build and load the updated code, and to begin debugging again.</p>



<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png"><img data-attachment-id="2281" data-permalink="https://blog.smittytone.net/pico-debug-session/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png" data-orig-size="1491,1055" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;0&quot;}" data-image-title="pico-debug-session" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png?w=625" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico-debug-session.png" alt="" class="wp-image-2281" srcset="https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png?w=1024 1024w, https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico-debug-session.png 1491w" sizes="(max-width: 1024px) 100vw, 1024px"></a><figcaption>A full debug session in Visual Studio Code</figcaption></figure></div>



<h4>Troubleshooting</h4>



<p>If you see debugging errors, check your wiring. I started out getting nothing back from OpenOCD but <code>DAP Init Failed</code> errors. I traced it down to an incorrectly grounded SWD GND pin. You may need to try different GND pins on the <em>picoprobe</em> Pico if this persists.</p>



<p>It’s also easy to mis-select the target or the compiler. </p>



<p>I’ve updated my <a rel="noreferrer noopener" href="https://github.com/smittytone/pi-pico" target="_blank">Pico repository on GitHub</a> with the new, debugger-friendly <code>launch.json</code> file.</p>



<h2 class="has-text-color" style="color:#4e65ae;">More on the Raspberry Pi Pico</h2>



<ul><li><a href="https://blog.smittytone.net/2021/08/30/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-two/">How to build a cellular IoT device with the Raspberry Pi Pico — part two, the&nbsp;code</a></li><li><a href="https://blog.smittytone.net/2021/08/20/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-one/">How to build a cellular IoT device with the Pico — part one, the&nbsp;hardware</a></li><li><a href="https://blog.smittytone.net/2021/07/24/how-to-pop-up-a-picoprobe-from-the-adafruit-qy-py-rp2040/">How to pop up a Picoprobe from the Adafruit QT Py&nbsp;RP2040</a></li><li><a href="https://blog.smittytone.net/2021/07/02/raspberry-pi-pico-proxies-pimoroni-tiny-2040-adafruit-qt-py-rp2040/">Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py&nbsp;RP2040</a></li><li><a href="https://blog.smittytone.net/2021/04/30/c-plus-plus-on-the-raspberry-pi-pico/">Introducing C++ programming on the Raspberry Pi Pico</a></li><li><a href="https://blog.smittytone.net/2021/03/26/3d-arcade-action-courtesy-of-raspberry-pi-pico/">Enjoy some old school 3D arcade action — courtesy of the Raspberry Pi&nbsp;Pico</a></li><li><a href="https://blog.smittytone.net/2021/02/20/hunt-the-wumpus-raspberry-pi-pico-style/">Play Hunt the Wumpus, Raspberry Pi Pico&nbsp;style</a>&nbsp;</li><li><a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/">How to Program the Raspberry Pi Pico in C on a Mac</a></li><li><a href="https://blog.smittytone.net/2021/01/23/first-look-the-raspberry-pi-pico-on-mac/">A First Look at a MicroPython Marvel: the Raspberry Pi Pico</a></li></ul>



<p></p>
<div id="jp-post-flair" class="sharedaddy sd-rating-enabled sd-like-enabled sd-sharing-enabled"><div class="sd-block sd-rating"><h3 class="sd-title">Rate this:</h3><div class="cs-rating pd-rating" id="pd_rating_holder_1209223_post_2258" style="display: inline-block;"><div class="rating-icons" id="pd_rate_1209223_post_2258" style="float:left;"><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2258.rebuild();" onclick="PDRTJS_1209223_post_2258.rate(1);" onmouseover="PDRTJS_1209223_post_2258.hover(1);" id="PDRTJS_1209223_post_2258_stars_1" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2258.rebuild();" onclick="PDRTJS_1209223_post_2258.rate(2);" onmouseover="PDRTJS_1209223_post_2258.hover(2);" id="PDRTJS_1209223_post_2258_stars_2" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2258.rebuild();" onclick="PDRTJS_1209223_post_2258.rate(3);" onmouseover="PDRTJS_1209223_post_2258.hover(3);" id="PDRTJS_1209223_post_2258_stars_3" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2258.rebuild();" onclick="PDRTJS_1209223_post_2258.rate(4);" onmouseover="PDRTJS_1209223_post_2258.hover(4);" id="PDRTJS_1209223_post_2258_stars_4" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div><div class="rating-star-icon" onmouseout="PDRTJS_1209223_post_2258.rebuild();" onclick="PDRTJS_1209223_post_2258.rate(5);" onmouseover="PDRTJS_1209223_post_2258.hover(5);" id="PDRTJS_1209223_post_2258_stars_5" style="background-size: 32px 48px !important; cursor: pointer; width: 16px; height: 16px; line-height: 16px; background: url(https://polldaddy.com/images/ratings/star-yellow-sml@2x.png) top left; float: left; padding: 0px; margin: 0px; margin-right: 1px;">&nbsp;</div></div><span style="float:left;">&nbsp;</span><div id="rating_info_1209223_post_2258" style="display:block;float:left;background:url(https://polldaddy.com/images/ratings/info@2x.png) no-repeat 3px 2px;width:16px;height:16px;cursor:pointer; background-size:12px 12px; " onclick="javascript:PDRTJS_1209223_post_2258.togglePopup();return false;"><span style="display:none;">i</span></div><div class="pd_popup_holder" id="pd_popup_holder_1209223_post_2258">&nbsp;</div><div class="rating-msg" id="PDRTJS_1209223_post_2258_msg" style="float:left; padding-left: 5px; text-align: left; font:normal normal /16px ; color: #;">1 Votes</div><p style="padding: 0px; margin: 0px; clear: both;"></p></div></div><div class="sharedaddy sd-sharing-enabled"><div class="robots-nocontent sd-block sd-social sd-social-icon sd-sharing"><h3 class="sd-title">Share this:</h3><div class="sd-content"><ul data-sharing-events-added="true"><li class="share-twitter"><a rel="nofollow noopener noreferrer" data-shared="sharing-twitter-2258" class="share-twitter sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=twitter&amp;nb=1" target="_blank" title="Click to share on Twitter"><span></span><span class="sharing-screen-reader-text">Click to share on Twitter (Opens in new window)</span></a></li><li class="share-reddit"><a rel="nofollow noopener noreferrer" data-shared="" class="share-reddit sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=reddit&amp;nb=1" target="_blank" title="Click to share on Reddit"><span></span><span class="sharing-screen-reader-text">Click to share on Reddit (Opens in new window)</span></a></li><li class="share-tumblr"><a rel="nofollow noopener noreferrer" data-shared="" class="share-tumblr sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=tumblr&amp;nb=1" target="_blank" title="Click to share on Tumblr"><span></span><span class="sharing-screen-reader-text">Click to share on Tumblr (Opens in new window)</span></a></li><li class="share-pinterest"><a rel="nofollow noopener noreferrer" data-shared="sharing-pinterest-2258" class="share-pinterest sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=pinterest&amp;nb=1" target="_blank" title="Click to share on Pinterest"><span></span><span class="sharing-screen-reader-text">Click to share on Pinterest (Opens in new window)</span></a></li><li class="share-linkedin"><a rel="nofollow noopener noreferrer" data-shared="sharing-linkedin-2258" class="share-linkedin sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=linkedin&amp;nb=1" target="_blank" title="Click to share on LinkedIn"><span></span><span class="sharing-screen-reader-text">Click to share on LinkedIn (Opens in new window)</span></a></li><li class="share-email share-service-visible"><a rel="nofollow noopener noreferrer" data-shared="" class="share-email sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=email&amp;nb=1" target="_blank" title="Click to email this to a friend"><span></span><span class="sharing-screen-reader-text">Click to email this to a friend (Opens in new window)</span></a></li><li class="share-facebook"><a rel="nofollow noopener noreferrer" data-shared="sharing-facebook-2258" class="share-facebook sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=facebook&amp;nb=1" target="_blank" title="Click to share on Facebook"><span></span><span class="sharing-screen-reader-text">Click to share on Facebook (Opens in new window)</span></a></li><li class="share-jetpack-whatsapp"><a rel="nofollow noopener noreferrer" data-shared="" class="share-jetpack-whatsapp sd-button share-icon no-text" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/?share=jetpack-whatsapp&amp;nb=1" target="_blank" title="Click to share on WhatsApp"><span></span><span class="sharing-screen-reader-text">Click to share on WhatsApp (Opens in new window)</span></a></li><li class="share-end"></li></ul></div></div></div><div class="sharedaddy sd-block sd-like jetpack-likes-widget-wrapper jetpack-likes-widget-loaded" id="like-post-wrapper-11065590-2258-6185e1d3001bf" data-src="//widgets.wp.com/likes/index.html?ver=20210831#blog_id=11065590&amp;post_id=2258&amp;origin=smittytone.wordpress.com&amp;obj_id=11065590-2258-6185e1d3001bf&amp;domain=blog.smittytone.net" data-name="like-post-frame-11065590-2258-6185e1d3001bf" data-title="Like or Reblog"><h3 class="sd-title">Like this:</h3><div class="likes-widget-placeholder post-likes-widget-placeholder" style="height: 55px; display: none;"><span class="button"><span>Like</span></span> <span class="loading">Loading...</span></div><iframe class="post-likes-widget jetpack-likes-widget" name="like-post-frame-11065590-2258-6185e1d3001bf" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/index.html" height="55px" width="100%" frameborder="0" title="Like or Reblog"></iframe><span class="sd-text-color"></span><a class="sd-link-color"></a></div>
<div id="jp-relatedposts" class="jp-relatedposts" style="display: block;">
	<h3 class="jp-relatedposts-headline"><em>Related</em></h3>
<div class="jp-relatedposts-items jp-relatedposts-items-visual jp-relatedposts-grid "><div class="jp-relatedposts-post jp-relatedposts-post0 jp-relatedposts-post-thumbs" data-post-id="2224" data-post-format="false"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?relatedposts_hit=1&amp;relatedposts_origin=2258&amp;relatedposts_position=0" title="How to program the Raspberry Pi Pico in C on a Mac" data-origin="2258" data-position="0"><img class="jp-relatedposts-post-img" loading="lazy" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico.jpg" width="193" alt="" height="110" srcset="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=193&amp;h=110&amp;crop=1&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=350&amp;h=200&amp;crop=1" scale="2"></a><h4 class="jp-relatedposts-post-title"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/?relatedposts_hit=1&amp;relatedposts_origin=2258&amp;relatedposts_position=0" title="How to program the Raspberry Pi Pico in C on a Mac" data-origin="2258" data-position="0">How to program the Raspberry Pi Pico in C on a&nbsp;Mac</a></h4><p class="jp-relatedposts-post-excerpt">Last week I tried the Raspberry Pi Pico with MicroPython. The Raspberry Pi Foundation would be sufficiently commended for providing only this level of programming support. MicroPython leverages the Python skills of the many Raspberry Pi users out there and is accessible to plenty of others too. But the Foundation…</p><time class="jp-relatedposts-post-date" datetime="February 2, 2021" style="display: block;">February 2, 2021</time><p class="jp-relatedposts-post-context">In "How To (Mac)"</p></div><div class="jp-relatedposts-post jp-relatedposts-post1 jp-relatedposts-post-thumbs" data-post-id="2858" data-post-format="false"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/24/how-to-pop-up-a-picoprobe-from-the-adafruit-qy-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2258&amp;relatedposts_position=1" title="How to pop up a Picoprobe from the Adafruit QT Py RP2040" data-origin="2258" data-position="1"><img class="jp-relatedposts-post-img" loading="lazy" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/p1020082.jpg" width="193" alt="" height="110" srcset="https://smittytone.files.wordpress.com/2021/07/p1020082.jpg?w=193&amp;h=110&amp;crop=1&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/07/p1020082.jpg?w=350&amp;h=200&amp;crop=1" scale="2"></a><h4 class="jp-relatedposts-post-title"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/24/how-to-pop-up-a-picoprobe-from-the-adafruit-qy-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2258&amp;relatedposts_position=1" title="How to pop up a Picoprobe from the Adafruit QT Py RP2040" data-origin="2258" data-position="1">How to pop up a Picoprobe from the Adafruit QT Py&nbsp;RP2040</a></h4><p class="jp-relatedposts-post-excerpt">A little while back I wrote about Adafruit's QT Py RP2040 and how it makes a nice, compact Picoprobe. That’s a Raspberry Pi RP2040-based device used as a bridge between your computer and a target device for debugging work using Single Wire Debug (SWD). I first used the QT Py…</p><time class="jp-relatedposts-post-date" datetime="July 24, 2021" style="display: block;">July 24, 2021</time><p class="jp-relatedposts-post-context">In "How To (Pi)"</p></div><div class="jp-relatedposts-post jp-relatedposts-post2 jp-relatedposts-post-thumbs" data-post-id="2776" data-post-format="false"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/02/raspberry-pi-pico-proxies-pimoroni-tiny-2040-adafruit-qt-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2258&amp;relatedposts_position=2" title="Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py RP2040" data-origin="2258" data-position="2"><img class="jp-relatedposts-post-img" loading="lazy" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/p1020086-1.jpg" width="193" alt="" height="110" srcset="https://smittytone.files.wordpress.com/2021/07/p1020086-1.jpg?w=193&amp;h=110&amp;crop=1&amp;zoom=2 2x" src-orig="https://smittytone.files.wordpress.com/2021/07/p1020086-1.jpg?w=350&amp;h=200&amp;crop=1" scale="2"></a><h4 class="jp-relatedposts-post-title"><a class="jp-relatedposts-post-a" href="https://blog.smittytone.net/2021/07/02/raspberry-pi-pico-proxies-pimoroni-tiny-2040-adafruit-qt-py-rp2040/?relatedposts_hit=1&amp;relatedposts_origin=2258&amp;relatedposts_position=2" title="Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py RP2040" data-origin="2258" data-position="2">Raspberry Pi Pico proxies: the Pimoroni Tiny 2040 and the Adafruit QT Py&nbsp;RP2040</a></h4><p class="jp-relatedposts-post-excerpt">Having spent some time with the Raspberry Pi Pico, I thought it was time to try out some of the other RP2040-based development boards that have become available. When it launched the Pico, the Raspberry Pi Foundation said it would make its RP2040 microcontroller available to third-party board makers. Retailers…</p><time class="jp-relatedposts-post-date" datetime="July 2, 2021" style="display: block;">July 2, 2021</time><p class="jp-relatedposts-post-context">In "Raspberry Pi"</p></div></div></div></div>					</div><!-- .entry-content -->
		
		<footer class="entry-meta">
			This entry was posted in <a href="https://blog.smittytone.net/category/how-to-mac/" rel="category tag">How To (Mac)</a>, <a href="https://blog.smittytone.net/category/how-to-pi/" rel="category tag">How To (Pi)</a>, <a href="https://blog.smittytone.net/category/raspberry-pi/" rel="category tag">Raspberry Pi</a> and tagged <a href="https://blog.smittytone.net/tag/mac/" rel="tag">Mac</a>, <a href="https://blog.smittytone.net/tag/macos/" rel="tag">macos</a>, <a href="https://blog.smittytone.net/tag/osx/" rel="tag">osx</a>, <a href="https://blog.smittytone.net/tag/pico/" rel="tag">Pico</a>, <a href="https://blog.smittytone.net/tag/raspberry-pi/" rel="tag">Raspberry Pi</a>, <a href="https://blog.smittytone.net/tag/swd/" rel="tag">swd</a> on <a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/" title="8:10 am" rel="bookmark"><time class="entry-date" datetime="2021-02-05T08:10:48+00:00">February 5, 2021</time></a><span class="by-author"> by <span class="author vcard"><a class="url fn n" href="https://blog.smittytone.net/author/smittytone/" title="View all posts by smittytone" rel="author">smittytone</a></span></span>.								</footer><!-- .entry-meta -->
	</article><!-- #post -->

				<nav class="nav-single">
					<h3 class="assistive-text">Post navigation</h3>
					<span class="nav-previous"><a href="https://blog.smittytone.net/2021/02/02/program-raspberry-pi-pico-c-mac/" rel="prev"><span class="meta-nav">←</span> How to program the Raspberry Pi Pico in C on a&nbsp;Mac</a></span>
					<span class="nav-next"><a href="https://blog.smittytone.net/2021/02/07/how-to-migrate-to-native-homebrew-on-an-m1-mac/" rel="next">How to migrate to native Homebrew on an M1&nbsp;Mac <span class="meta-nav">→</span></a></span>
				</nav><!-- .nav-single -->

				
<div id="comments" class="comments-area">

	
			<h2 class="comments-title">
			7 thoughts on “<span>How to debug a Raspberry Pi Pico with a Mac, SWD and… another&nbsp;Pico</span>”		</h2>

		<ol class="commentlist">
				<li class="comment even thread-even depth-1 highlander-comment" id="li-comment-5855">
		<article id="comment-5855" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/ad516503a11cd5ca435acc9bb6523536.png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://0.gravatar.com/avatar/9a9249ad4eba4a0922fec499556ec8f2?s=44&amp;d=https%3A%2F%2F0.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-9a9249ad4eba4a0922fec499556ec8f2-0"><cite><b class="fn">Leon</b> </cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-5855"><time datetime="2021-03-10T22:09:08+00:00">March 10, 2021 at 10:09 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>You need to initialize the submodules of pico-sdk to run `make -j4`. Just run `git submodule update –init` in the sdk directory.</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				</li><!-- #comment-## -->
	<li class="comment odd alt thread-odd thread-alt depth-1 highlander-comment" id="li-comment-5202">
		<article id="comment-5202" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/ad516503a11cd5ca435acc9bb6523536(1).png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://2.gravatar.com/avatar/27bd0b2827495be76f0c59cdf05fcb07?s=44&amp;d=https%3A%2F%2F2.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-27bd0b2827495be76f0c59cdf05fcb07-0"><cite><b class="fn"><a href="https://github.com/majbthrd/pico-debug/" rel="external nofollow ugc" class="url">Peter Lawrence</a></b> </cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-5202"><time datetime="2021-02-15T01:35:56+00:00">February 15, 2021 at 1:35 am</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Just to add to my previous comment: to adapt the above example to work with pico-debug, one needs to use the newer pico-sdk and openocd referenced in the pico-debug howto subdirectory, and then the launch.js changes like so (WP will probably lose the line feeds):</p>
<p>Replace:<br>
             “configFiles”: [<br>
                 “/interface/picoprobe.cfg”,<br>
                 “/target/rp2040.cfg”<br>
             ],<br>
with:<br>
             “configFiles”: [<br>
                 “interface/cmsis-dap.cfg”,<br>
                 “target/rp2040-core0.cfg”<br>
             ],<br>
             “openOCDLaunchCommands”: [<br>
                 “transport select swd”,<br>
                 “adapter speed 4000”<br>
             ],</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				</li><!-- #comment-## -->
	<li class="comment even thread-even depth-1 highlander-comment" id="li-comment-5193">
		<article id="comment-5193" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/ad516503a11cd5ca435acc9bb6523536(1).png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://2.gravatar.com/avatar/27bd0b2827495be76f0c59cdf05fcb07?s=44&amp;d=https%3A%2F%2F2.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-27bd0b2827495be76f0c59cdf05fcb07-1"><cite><b class="fn"><a href="https://github.com/majbthrd/pico-debug/" rel="external nofollow ugc" class="url">Peter Lawrence</a></b> </cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-5193"><time datetime="2021-02-14T22:01:08+00:00">February 14, 2021 at 10:01 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Have you tried pico-debug?  I wrote it to debug with just a single RP2040: <a href="https://github.com/majbthrd/pico-debug/" rel="nofollow ugc">https://github.com/majbthrd/pico-debug/</a>  As long as you are not trying to debug RP2040 code that uses the USB peripheral, OpenOCD talks directly to the very RP2040 being debugged, and no extra wiring is needed.  There are instructions in the howto subdirectory.  Anyone doing a web search at the moment for pico debugging gets told that they have to use picoprobe and two RP2040, and I wanted to point out that this is not true.  Thanks.</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				<ol class="children">
	<li class="comment byuser comment-author-smittytone bypostauthor odd alt depth-2 highlander-comment" id="li-comment-5215">
		<article id="comment-5215" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/10fec714bdedc593cd7e9e2f250e10b8.png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://1.gravatar.com/avatar/10fec714bdedc593cd7e9e2f250e10b8?s=44&amp;d=https%3A%2F%2F1.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-10fec714bdedc593cd7e9e2f250e10b8-0"><cite><b class="fn"><a href="https://smittytone.wordpress.com/" rel="external nofollow ugc" class="url">smittytone</a></b> <span>Post author</span></cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-5215"><time datetime="2021-02-15T14:07:21+00:00">February 15, 2021 at 2:07 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Interesting. I shall try it. Initially, it looks like there may be Mac installation issues — and Mac is the focus of the Pico coverage here — due to using packages available on apt but not brew, but we’ll see.</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				<ol class="children">
	<li class="comment even depth-3 highlander-comment" id="li-comment-5218">
		<article id="comment-5218" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/ad516503a11cd5ca435acc9bb6523536(1).png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://2.gravatar.com/avatar/27bd0b2827495be76f0c59cdf05fcb07?s=44&amp;d=https%3A%2F%2F2.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-27bd0b2827495be76f0c59cdf05fcb07-2"><cite><b class="fn"><a href="https://github.com/majbthrd/pico-debug/" rel="external nofollow ugc" class="url">Peter Lawrence</a></b> </cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-5218"><time datetime="2021-02-15T17:03:41+00:00">February 15, 2021 at 5:03 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>I presume that you are talking about hidapi?  The CMSIS-DAP protocol has been around since 2013, and was intended from the start to work with macOS, Linux, and Windows.  I did a web search for “macos openocd cmsis-dap hid”; this link <a href="https://gist.github.com/technobly/f2c14eaa7334db80849d45614250bdf0" rel="nofollow ugc">https://gist.github.com/technobly/f2c14eaa7334db80849d45614250bdf0</a> provides steps; it is not clear to me why they use the Dashlane fork instead of the original signal11 repo.  Obviously, you don’t want to use the openocd download link in that gist; the recent openocd with Pico support pointed to in the pico-debug howto is needed.</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				</li><!-- #comment-## -->
</ol><!-- .children -->
</li><!-- #comment-## -->
</ol><!-- .children -->
</li><!-- #comment-## -->
	<li class="comment odd alt thread-odd thread-alt depth-1 highlander-comment" id="li-comment-4996">
		<article id="comment-4996" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/ad516503a11cd5ca435acc9bb6523536(2).png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://0.gravatar.com/avatar/c7fcc4d870b58d512df5b4f835fa25b3?s=44&amp;d=https%3A%2F%2F0.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-c7fcc4d870b58d512df5b4f835fa25b3-0"><cite><b class="fn">John</b> </cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-4996"><time datetime="2021-02-06T14:37:33+00:00">February 6, 2021 at 2:37 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Nice article, even though I’m on Linux it helped a lot! The wiring diagram is flipped though. The picoprobe connects to the target’s debug pins, not the other way around. See Appendix A3 in <a href="https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf" rel="nofollow ugc">https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf</a></p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				<ol class="children">
	<li class="comment byuser comment-author-smittytone bypostauthor even depth-2 highlander-comment" id="li-comment-4997">
		<article id="comment-4997" class="comment">
			<header class="comment-meta comment-author vcard">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/10fec714bdedc593cd7e9e2f250e10b8.png" class="avatar avatar-44 grav-hashed grav-hijack" height="44" width="44" originals="44" src-orig="https://1.gravatar.com/avatar/10fec714bdedc593cd7e9e2f250e10b8?s=44&amp;d=https%3A%2F%2F1.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D44&amp;r=R" scale="2" id="grav-10fec714bdedc593cd7e9e2f250e10b8-1"><cite><b class="fn"><a href="https://smittytone.wordpress.com/" rel="external nofollow ugc" class="url">smittytone</a></b> <span>Post author</span></cite><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#comment-4997"><time datetime="2021-02-06T16:01:17+00:00">February 6, 2021 at 4:01 pm</time></a>			</header><!-- .comment-meta -->

				
				
			<section class="comment-content comment">
				<p>Absolutely right, John —&nbsp;thank you! Diagram now fixed. Memo to self: check diagrams *before* publishing, next time.</p>
							</section><!-- .comment-content -->

				<div class="reply">
								</div><!-- .reply -->
			</article><!-- #comment-## -->
				</li><!-- #comment-## -->
</ol><!-- .children -->
</li><!-- #comment-## -->
		</ol><!-- .commentlist -->

		
				<p class="nocomments">Comments are closed.</p>
		
	
	
</div><!-- #comments .comments-area -->

			
		</div><!-- #content -->
	</div><!-- #primary -->


			<div id="secondary" class="widget-area" role="complementary">
						<aside id="follow_button_widget-3" class="widget widget_follow_button_widget">
		<iframe src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/index(1).html" width="100%" height="20" frameborder="0" scrolling="no"></iframe>
		<script type="text/javascript">(function(d){var f = d.getElementsByTagName('SCRIPT')[0], p = d.createElement('SCRIPT');p.type = 'text/javascript';p.async = true;p.src = '//widgets.wp.com/platform.js';f.parentNode.insertBefore(p,f);}(document));</script>

		</aside><aside id="block-3" class="widget widget_block widget_media_image">
<div class="wp-block-image"><figure class="aligncenter size-large"><a href="https://merch.smittytone.net/" target="_blank"><img loading="lazy" width="1624" height="1492" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/shirts.png" alt="" class="wp-image-2955"></a><figcaption>smittytone’s retro tech t-shirts</figcaption></figure></div>
</aside><aside id="media_image-3" class="widget widget_media_image"><h3 class="widget-title">Program the Raspberry Pi Pico</h3><style>.widget.widget_media_image { overflow: hidden; }.widget.widget_media_image img { height: auto; max-width: 100%; }</style><a href="https://blog.smittytone.net/tag/pico/"><img width="1120" height="514" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/pico(1).jpg" class="image wp-image-2238  attachment-1120x514 size-1120x514" alt="" loading="lazy" style="max-width: 100%; height: auto;" srcset="https://smittytone.files.wordpress.com/2021/02/pico.jpg 1120w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=150 150w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=300 300w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=768 768w, https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=1024 1024w" sizes="(max-width: 1120px) 100vw, 1120px" data-attachment-id="2238" data-permalink="https://blog.smittytone.net/pico/" data-orig-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg" data-orig-size="1120,514" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="pico" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=300" data-large-file="https://smittytone.files.wordpress.com/2021/02/pico.jpg?w=625"></a></aside>
		<aside id="recent-posts-4" class="widget widget_recent_entries">
		<h3 class="widget-title">Latest Items</h3>
		<ul>
											<li>
					<a href="https://blog.smittytone.net/2021/10/31/how-to-send-data-to-a-raspberry-pi-pico-via-usb/">How to send data to a Raspberry Pi Pico via&nbsp;USB</a>
											<span class="post-date">October 31, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/10/16/first-look-pimoroni-picosystem-hackable-handheld-games-console/">First look: Pimoroni’s PicoSystem hackable handheld games&nbsp;console</a>
											<span class="post-date">October 16, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/10/02/clive-sinclair-1941-2021-part-three-resurgam/">Clive Sinclair (1941-2021) Part three —&nbsp;resurgam</a>
											<span class="post-date">October 2, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/09/24/clive-sinclair-1940-2021-part-two-radionics-last-great-hope-the-microcomputer/">Clive Sinclair (1940-2021) Part two —&nbsp;Radionics’ last, great hope: the&nbsp;microcomputer</a>
											<span class="post-date">September 24, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/09/16/sir-clive-sinclair-1940-2021-how-it-all-began/">Clive Sinclair (1940-2021) Part one — how it all&nbsp;began</a>
											<span class="post-date">September 16, 2021</span>
									</li>
											<li>
					<a href="https://blog.smittytone.net/2021/08/30/how-to-build-a-cellular-iot-device-with-raspberry-pi-pico-part-two/">How to build a cellular IoT device with the Raspberry Pi Pico — part two, the&nbsp;code</a>
											<span class="post-date">August 30, 2021</span>
									</li>
					</ul>

		</aside><aside id="media_image-5" class="widget widget_media_image"><h3 class="widget-title">Enjoyed using this site? Tip me!</h3><style>.widget.widget_media_image { overflow: hidden; }.widget.widget_media_image img { height: auto; max-width: 100%; }</style><img width="625" height="694" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/img_0604.jpg" class="image wp-image-2614  attachment-full size-full" alt="Tip QR Code" loading="lazy" style="max-width: 100%; height: auto;" srcset="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=625&amp;h=694 625w, https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=135&amp;h=150 135w, https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=270&amp;h=300 270w, https://smittytone.files.wordpress.com/2021/04/img_0604.jpg 648w" sizes="(max-width: 625px) 100vw, 625px" data-attachment-id="2614" data-permalink="https://blog.smittytone.net/img_0604/" data-orig-file="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg" data-orig-size="648,720" data-comments-opened="1" data-image-meta="{&quot;aperture&quot;:&quot;0&quot;,&quot;credit&quot;:&quot;&quot;,&quot;camera&quot;:&quot;&quot;,&quot;caption&quot;:&quot;&quot;,&quot;created_timestamp&quot;:&quot;0&quot;,&quot;copyright&quot;:&quot;&quot;,&quot;focal_length&quot;:&quot;0&quot;,&quot;iso&quot;:&quot;0&quot;,&quot;shutter_speed&quot;:&quot;0&quot;,&quot;title&quot;:&quot;&quot;,&quot;orientation&quot;:&quot;1&quot;}" data-image-title="IMG_0604" data-image-description="" data-image-caption="" data-medium-file="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=270" data-large-file="https://smittytone.files.wordpress.com/2021/04/img_0604.jpg?w=625"></aside><aside id="custom_html-3" class="widget_text widget widget_custom_html"><h3 class="widget-title">My Sites</h3><div class="textwidget custom-html-widget"><ul>
	<li><a href="https://smittytone.net/">smittytone’s software stack</a></li>
	<li><a href="https://code.smittytone.net/">GitHub</a></li>
	<li><a href="https://www.linkedin.com/in/smittytone/">LinkedIn</a></li>
	<li><a href="https://merch.smittytone.net/">Merch</a></li>
</ul></div></aside><aside id="pages-4" class="widget widget_pages"><h3 class="widget-title">Other Items</h3>
			<ul>
				<li class="page_item page-item-2"><a href="https://blog.smittytone.net/about/">About ‘Smittytone Messes with&nbsp;Micros’</a></li>
<li class="page_item page-item-1477"><a href="https://blog.smittytone.net/pi-knowledgebase/">Raspberry Pi Knowledgebase</a></li>
			</ul>

			</aside><aside id="categories-4" class="widget widget_categories"><h3 class="widget-title">Site Topics</h3>
			<ul>
					<li class="cat-item cat-item-4213"><a href="https://blog.smittytone.net/category/apps/">apps</a>
</li>
	<li class="cat-item cat-item-4843"><a href="https://blog.smittytone.net/category/hacks/">Hacks</a>
</li>
	<li class="cat-item cat-item-9333085"><a href="https://blog.smittytone.net/category/how-to-mac/">How To (Mac)</a>
</li>
	<li class="cat-item cat-item-323292718"><a href="https://blog.smittytone.net/category/how-to-pi/">How To (Pi)</a>
</li>
	<li class="cat-item cat-item-2121118"><a href="https://blog.smittytone.net/category/iot/">IoT</a>
</li>
	<li class="cat-item cat-item-808"><a href="https://blog.smittytone.net/category/mac/">Mac</a>
</li>
	<li class="cat-item cat-item-120"><a href="https://blog.smittytone.net/category/mobile/">Mobile</a>
</li>
	<li class="cat-item cat-item-196"><a href="https://blog.smittytone.net/category/programming/">Programming</a>
</li>
	<li class="cat-item cat-item-49695267"><a href="https://blog.smittytone.net/category/raspberry-pi/">Raspberry Pi</a>
</li>
	<li class="cat-item cat-item-1445"><a href="https://blog.smittytone.net/category/retro/">Retro</a>
</li>
	<li class="cat-item cat-item-309"><a href="https://blog.smittytone.net/category/reviews/">Reviews</a>
</li>
	<li class="cat-item cat-item-287954"><a href="https://blog.smittytone.net/category/sidelines/">Sidelines</a>
</li>
	<li class="cat-item cat-item-36477"><a href="https://blog.smittytone.net/category/vintage-computing/">Vintage Computing</a>
</li>
	<li class="cat-item cat-item-362282"><a href="https://blog.smittytone.net/category/webwork/">Webwork</a>
</li>
	<li class="cat-item cat-item-355"><a href="https://blog.smittytone.net/category/wireless/">Wireless</a>
</li>
			</ul>

			</aside><aside id="follow_button_widget-5" class="widget widget_follow_button_widget">
		<iframe src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/index(2).html" width="100%" height="20" frameborder="0" scrolling="no"></iframe>
		<script type="text/javascript">(function(d){var f = d.getElementsByTagName('SCRIPT')[0], p = d.createElement('SCRIPT');p.type = 'text/javascript';p.async = true;p.src = '//widgets.wp.com/platform.js';f.parentNode.insertBefore(p,f);}(document));</script>

		</aside><aside id="block-4" class="widget widget_block widget_text">
<p></p>
</aside>		</div><!-- #secondary -->
		</div><!-- #main .wrapper -->
	<footer id="colophon" role="contentinfo">
		<div class="site-info">
									<a href="https://wordpress.com/?ref=footer_custom_powered" rel="nofollow">Website Powered by WordPress.com</a>.
		</div><!-- .site-info -->
	</footer><!-- #colophon -->
</div><!-- #page -->

<!--  -->
<script src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/gprofiles.js" id="grofiles-cards-js"></script>
<script id="wpgroho-js-extra">
var WPGroHo = {"my_hash":""};
</script>
<script crossorigin="anonymous" type="text/javascript" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/wpgroho.js"></script>

	<script>
		// Initialize and attach hovercards to all gravatars
		( function() {
			function init() {
				if ( typeof Gravatar === 'undefined' ) {
					return;
				}

				if ( typeof Gravatar.init !== 'function' ) {
					return;
				}

				Gravatar.profile_cb = function ( hash, id ) {
					WPGroHo.syncProfileData( hash, id );
				};

				Gravatar.my_hash = WPGroHo.my_hash;
				Gravatar.init( 'body', '#wp-admin-bar-my-account' );
			}

			if ( document.readyState !== 'loading' ) {
				init();
			} else {
				document.addEventListener( 'DOMContentLoaded', init );
			}
		} )();
	</script>

		<div style="display:none">
	<div class="grofile-hash-map-9a9249ad4eba4a0922fec499556ec8f2">
	</div>
	<div class="grofile-hash-map-27bd0b2827495be76f0c59cdf05fcb07">
	</div>
	<div class="grofile-hash-map-10fec714bdedc593cd7e9e2f250e10b8">
	</div>
	<div class="grofile-hash-map-c7fcc4d870b58d512df5b4f835fa25b3">
	</div>
	</div>
<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-dark-grayscale"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 0.49803921568627"></fefuncr><fefuncg type="table" tableValues="0 0.49803921568627"></fefuncg><fefuncb type="table" tableValues="0 0.49803921568627"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-grayscale"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 1"></fefuncr><fefuncg type="table" tableValues="0 1"></fefuncg><fefuncb type="table" tableValues="0 1"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-purple-yellow"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.54901960784314 0.98823529411765"></fefuncr><fefuncg type="table" tableValues="0 1"></fefuncg><fefuncb type="table" tableValues="0.71764705882353 0.25490196078431"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-blue-red"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 1"></fefuncr><fefuncg type="table" tableValues="0 0.27843137254902"></fefuncg><fefuncb type="table" tableValues="0.5921568627451 0.27843137254902"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-midnight"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0 0"></fefuncr><fefuncg type="table" tableValues="0 0.64705882352941"></fefuncg><fefuncb type="table" tableValues="0 1"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-magenta-yellow"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.78039215686275 1"></fefuncr><fefuncg type="table" tableValues="0 0.94901960784314"></fefuncg><fefuncb type="table" tableValues="0.35294117647059 0.47058823529412"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-purple-green"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.65098039215686 0.40392156862745"></fefuncr><fefuncg type="table" tableValues="0 1"></fefuncg><fefuncb type="table" tableValues="0.44705882352941 0.4"></fefuncb></fecomponenttransfer></filter></defs></svg><svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 0 0" width="0" height="0" focusable="false" role="none" style="visibility: hidden; position: absolute; left: -9999px; overflow: hidden;"><defs><filter id="wp-duotone-blue-orange"><fecolormatrix type="matrix" values=" .299 .587 .114 0 0 .299 .587 .114 0 0 .299 .587 .114 0 0 0 0 0 1 0 "></fecolormatrix><fecomponenttransfer color-interpolation-filters="sRGB"><fefuncr type="table" tableValues="0.098039215686275 1"></fefuncr><fefuncg type="table" tableValues="0 0.66274509803922"></fefuncg><fefuncb type="table" tableValues="0.84705882352941 0.41960784313725"></fefuncb></fecomponenttransfer></filter></defs></svg>	<div id="actionbar" class="actnbr-pub-twentytwelve actnbr-has-follow">
		<ul>
														<li class="actnbr-btn actnbr-hidden">
								<a class="actnbr-action actnbr-actn-follow " href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
			<svg class="gridicon gridicons-reader-follow" height="24" width="24" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 16v2h-3v3h-2v-3h-3v-2h3v-3h2v3h3zM20 2v9h-4v3h-3v4H4c-1.1 0-2-.9-2-2V2h18zM8 13v-1H4v1h4zm3-3H4v1h7v-1zm0-2H4v1h7V8zm7-4H4v2h14V4z"></path></g></svg><span>Follow</span>
		</a>
		<a class="actnbr-action actnbr-actn-following  no-display" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
			<svg class="gridicon gridicons-reader-following" height="24" width="24" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 13.482L15.508 21 12 17.4l1.412-1.388 2.106 2.188 6.094-6.094L23 13.482zm-7.455 1.862L20 10.89V2H2v14c0 1.1.9 2 2 2h4.538l4.913-4.832 2.095 2.176zM8 13H4v-1h4v1zm3-2H4v-1h7v1zm0-2H4V8h7v1zm7-3H4V4h14v2z"></path></g></svg><span>Following</span>
		</a>
							<div class="actnbr-popover tip tip-top-left actnbr-notice" id="follow-bubble">
							<div class="tip-arrow"></div>
							<div class="tip-inner actnbr-follow-bubble">
															<ul>
											<li class="actnbr-sitename">
			<a href="https://blog.smittytone.net/">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/cropped-rassilonblackwhite.png" class="avatar avatar-50" height="50" width="50" srcset="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=50&amp;zoom=2 2x" scale="2">				smittytone messes with micros			</a>
		</li>
										<form method="post" action="https://subscribe.wordpress.com/" accept-charset="utf-8" style="display: none;">
																						<div class="actnbr-follow-count">Join 139 other followers</div>
																					<div>
											<input type="email" name="email" placeholder="Enter your email address" class="actnbr-email-field">
										</div>
										<input type="hidden" name="action" value="subscribe">
										<input type="hidden" name="blog_id" value="11065590">
										<input type="hidden" name="source" value="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
										<input type="hidden" name="sub-type" value="actionbar-follow">
										<input type="hidden" id="_wpnonce" name="_wpnonce" value="8462703bb7">										<div class="actnbr-button-wrap">
											<button type="submit" value="Sign me up">
												Sign me up											</button>
										</div>
									</form>
									<li class="actnbr-login-nudge">
										<div>
											Already have a WordPress.com account? <a href="https://wordpress.com/log-in?redirect_to=https%3A%2F%2Fr-login.wordpress.com%2Fremote-login.php%3Faction%3Dlink%26back%3Dhttps%253A%252F%252Fblog.smittytone.net%252F2021%252F02%252F05%252Fhow-to-debug-a-raspberry-pi-pico-with-a-mac-swd%252F">Log in now.</a>										</div>
									</li>
								</ul>
															</div>
						</div>
					</li>
							<li class="actnbr-ellipsis actnbr-hidden">
				<svg class="gridicon gridicons-ellipsis" height="24" width="24" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M7 12c0 1.104-.896 2-2 2s-2-.896-2-2 .896-2 2-2 2 .896 2 2zm12-2c-1.104 0-2 .896-2 2s.896 2 2 2 2-.896 2-2-.896-2-2-2zm-7 0c-1.104 0-2 .896-2 2s.896 2 2 2 2-.896 2-2-.896-2-2-2z"></path></g></svg>				<div class="actnbr-popover tip tip-top-left actnbr-more">
					<div class="tip-arrow"></div>
					<div class="tip-inner">
						<ul>
									<li class="actnbr-sitename">
			<a href="https://blog.smittytone.net/">
				<img alt="" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/cropped-rassilonblackwhite.png" class="avatar avatar-50" height="50" width="50" srcset="https://smittytone.files.wordpress.com/2020/07/cropped-rassilonblackwhite.png?w=50&amp;zoom=2 2x" scale="2">				smittytone messes with micros			</a>
		</li>
								<li class="actnbr-folded-customize">
								<a href="https://smittytone.wordpress.com/wp-admin/customize.php?url=https%3A%2F%2Fsmittytone.wordpress.com%2F2021%2F02%2F05%2Fhow-to-debug-a-raspberry-pi-pico-with-a-mac-swd%2F">
									<svg class="gridicon gridicons-customize" height="20" width="20" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M2 6c0-1.505.78-3.08 2-4 0 .845.69 2 2 2 1.657 0 3 1.343 3 3 0 .386-.08.752-.212 1.09.74.594 1.476 1.19 2.19 1.81L8.9 11.98c-.62-.716-1.214-1.454-1.807-2.192C6.753 9.92 6.387 10 6 10c-2.21 0-4-1.79-4-4zm12.152 6.848l1.34-1.34c.607.304 1.283.492 2.008.492 2.485 0 4.5-2.015 4.5-4.5 0-.725-.188-1.4-.493-2.007L18 9l-2-2 3.507-3.507C18.9 3.188 18.225 3 17.5 3 15.015 3 13 5.015 13 7.5c0 .725.188 1.4.493 2.007L3 20l2 2 6.848-6.848c1.885 1.928 3.874 3.753 5.977 5.45l1.425 1.148 1.5-1.5-1.15-1.425c-1.695-2.103-3.52-4.092-5.448-5.977z"></path></g></svg>									<span>Customize</span>
								</a>
							</li>
																<li class="actnbr-folded-follow">
												<a class="actnbr-action actnbr-actn-follow " href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
			<svg class="gridicon gridicons-reader-follow" height="24" width="24" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 16v2h-3v3h-2v-3h-3v-2h3v-3h2v3h3zM20 2v9h-4v3h-3v4H4c-1.1 0-2-.9-2-2V2h18zM8 13v-1H4v1h4zm3-3H4v1h7v-1zm0-2H4v1h7V8zm7-4H4v2h14V4z"></path></g></svg><span>Follow</span>
		</a>
		<a class="actnbr-action actnbr-actn-following  no-display" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">
			<svg class="gridicon gridicons-reader-following" height="24" width="24" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24"><g><path d="M23 13.482L15.508 21 12 17.4l1.412-1.388 2.106 2.188 6.094-6.094L23 13.482zm-7.455 1.862L20 10.89V2H2v14c0 1.1.9 2 2 2h4.538l4.913-4.832 2.095 2.176zM8 13H4v-1h4v1zm3-2H4v-1h7v1zm0-2H4V8h7v1zm7-3H4V4h14v2z"></path></g></svg><span>Following</span>
		</a>
										</li>
																								<li class="actnbr-signup"><a href="https://wordpress.com/start/">Sign up</a></li>
									<li class="actnbr-login"><a href="https://wordpress.com/log-in?redirect_to=https%3A%2F%2Fr-login.wordpress.com%2Fremote-login.php%3Faction%3Dlink%26back%3Dhttps%253A%252F%252Fblog.smittytone.net%252F2021%252F02%252F05%252Fhow-to-debug-a-raspberry-pi-pico-with-a-mac-swd%252F">Log in</a></li>
																								<li class="actnbr-shortlink"><a href="https://wp.me/pKqFg-Aq">Copy shortlink</a></li>
																								<li class="flb-report"><a href="http://en.wordpress.com/abuse/">Report this content</a></li>
																								<li class="actnbr-reader">
										<a href="https://wordpress.com/read/blogs/11065590/posts/2258">
											View post in Reader										</a>
									</li>
																								<li class="actnbr-subs">
										<a href="https://subscribe.wordpress.com/">Manage subscriptions</a>
									</li>
																									<li class="actnbr-fold"><a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/">Collapse this bar</a></li>
															</ul>
					</div>
				</div>
			</li>
		</ul>
	</div>
	
<script>
window.addEventListener( "load", function( event ) {
	var link = document.createElement( "link" );
	link.href = "https://s0.wp.com/wp-content/mu-plugins/actionbar/actionbar.css?v=20210915";
	link.type = "text/css";
	link.rel = "stylesheet";
	document.head.appendChild( link );

	var script = document.createElement( "script" );
	script.src = "https://s0.wp.com/wp-content/mu-plugins/actionbar/actionbar.js?v=20211028";
	script.defer = true;
	document.body.appendChild( script );
} );
</script>

			<div id="jp-carousel-loading-overlay">
			<div id="jp-carousel-loading-wrapper">
				<span id="jp-carousel-library-loading">&nbsp;</span>
			</div>
		</div>
		<div class="jp-carousel-overlay" style="display: none;">

		<div class="jp-carousel-container">
			<!-- The Carousel Swiper -->
			<div class="jp-carousel-wrap swiper-container jp-carousel-swiper-container jp-carousel-transitions" itemscope="" itemtype="https://schema.org/ImageGallery">
				<div class="jp-carousel swiper-wrapper"></div>
				<div class="jp-swiper-button-prev swiper-button-prev">
					<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
						<mask id="maskPrev" mask-type="alpha" maskUnits="userSpaceOnUse" x="8" y="6" width="9" height="12">
							<path d="M16.2072 16.59L11.6496 12L16.2072 7.41L14.8041 6L8.8335 12L14.8041 18L16.2072 16.59Z" fill="white"></path>
						</mask>
						<g mask="url(#maskPrev)">
							<rect x="0.579102" width="23.8823" height="24" fill="#FFFFFF"></rect>
						</g>
					</svg>
				</div>
				<div class="jp-swiper-button-next swiper-button-next">
					<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
						<mask id="maskNext" mask-type="alpha" maskUnits="userSpaceOnUse" x="8" y="6" width="8" height="12">
							<path d="M8.59814 16.59L13.1557 12L8.59814 7.41L10.0012 6L15.9718 12L10.0012 18L8.59814 16.59Z" fill="white"></path>
						</mask>
						<g mask="url(#maskNext)">
							<rect x="0.34375" width="23.8822" height="24" fill="#FFFFFF"></rect>
						</g>
					</svg>
				</div>
			</div>
			<!-- The main close buton -->
			<div class="jp-carousel-close-hint">
				<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
					<mask id="maskClose" mask-type="alpha" maskUnits="userSpaceOnUse" x="5" y="5" width="15" height="14">
						<path d="M19.3166 6.41L17.9135 5L12.3509 10.59L6.78834 5L5.38525 6.41L10.9478 12L5.38525 17.59L6.78834 19L12.3509 13.41L17.9135 19L19.3166 17.59L13.754 12L19.3166 6.41Z" fill="white"></path>
					</mask>
					<g mask="url(#maskClose)">
						<rect x="0.409668" width="23.8823" height="24" fill="#FFFFFF"></rect>
					</g>
				</svg>
			</div>
			<!-- Image info, comments and meta -->
			<div class="jp-carousel-info">
				<div class="jp-carousel-info-footer">
					<div class="jp-carousel-pagination-container">
						<div class="jp-swiper-pagination swiper-pagination"></div>
						<div class="jp-carousel-pagination"></div>
					</div>
					<div class="jp-carousel-photo-title-container">
						<h2 class="jp-carousel-photo-caption"></h2>
					</div>
					<div class="jp-carousel-photo-icons-container">
						<a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#" class="jp-carousel-icon-btn jp-carousel-icon-info" aria-label="Toggle photo metadata visibility">
							<span class="jp-carousel-icon">
								<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
									<mask id="maskInfo" mask-type="alpha" maskUnits="userSpaceOnUse" x="2" y="2" width="21" height="20">
										<path fill-rule="evenodd" clip-rule="evenodd" d="M12.7537 2C7.26076 2 2.80273 6.48 2.80273 12C2.80273 17.52 7.26076 22 12.7537 22C18.2466 22 22.7046 17.52 22.7046 12C22.7046 6.48 18.2466 2 12.7537 2ZM11.7586 7V9H13.7488V7H11.7586ZM11.7586 11V17H13.7488V11H11.7586ZM4.79292 12C4.79292 16.41 8.36531 20 12.7537 20C17.142 20 20.7144 16.41 20.7144 12C20.7144 7.59 17.142 4 12.7537 4C8.36531 4 4.79292 7.59 4.79292 12Z" fill="white"></path>
									</mask>
									<g mask="url(#maskInfo)">
										<rect x="0.8125" width="23.8823" height="24" fill="#FFFFFF"></rect>
									</g>
								</svg>
							</span>
						</a>
												<a href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#" class="jp-carousel-icon-btn jp-carousel-icon-comments" aria-label="Toggle photo comments visibility">
							<span class="jp-carousel-icon">
								<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
									<mask id="maskComments" mask-type="alpha" maskUnits="userSpaceOnUse" x="2" y="2" width="21" height="20">
										<path fill-rule="evenodd" clip-rule="evenodd" d="M4.3271 2H20.2486C21.3432 2 22.2388 2.9 22.2388 4V16C22.2388 17.1 21.3432 18 20.2486 18H6.31729L2.33691 22V4C2.33691 2.9 3.2325 2 4.3271 2ZM6.31729 16H20.2486V4H4.3271V18L6.31729 16Z" fill="white"></path>
									</mask>
									<g mask="url(#maskComments)">
										<rect x="0.34668" width="23.8823" height="24" fill="#FFFFFF"></rect>
									</g>
								</svg>

								<span class="jp-carousel-has-comments-indicator" aria-label="This image has comments."></span>
							</span>
						</a>
											</div>
				</div>
				<div class="jp-carousel-info-extra">
					<div class="jp-carousel-info-content-wrapper">
						<div class="jp-carousel-photo-title-container">
							<h2 class="jp-carousel-photo-title"></h2>
						</div>
						<div class="jp-carousel-comments-wrapper">
															<div id="jp-carousel-comments-loading">
									<span>Loading Comments...</span>
								</div>
								<div class="jp-carousel-comments"></div>
								<div id="jp-carousel-comment-form-container">
									<span id="jp-carousel-comment-form-spinner">&nbsp;</span>
									<div id="jp-carousel-comment-post-results"></div>
																														<form id="jp-carousel-comment-form">
												<label for="jp-carousel-comment-form-comment-field" class="screen-reader-text">Write a Comment...</label>
												<textarea name="comment" class="jp-carousel-comment-form-field jp-carousel-comment-form-textarea" id="jp-carousel-comment-form-comment-field" placeholder="Write a Comment..."></textarea>
												<div id="jp-carousel-comment-form-submit-and-info-wrapper">
													<div id="jp-carousel-comment-form-commenting-as">
																													<fieldset>
																<label for="jp-carousel-comment-form-email-field">Email (Required)</label>
																<input type="text" name="email" class="jp-carousel-comment-form-field jp-carousel-comment-form-text-field" id="jp-carousel-comment-form-email-field">
															</fieldset>
															<fieldset>
																<label for="jp-carousel-comment-form-author-field">Name (Required)</label>
																<input type="text" name="author" class="jp-carousel-comment-form-field jp-carousel-comment-form-text-field" id="jp-carousel-comment-form-author-field">
															</fieldset>
															<fieldset>
																<label for="jp-carousel-comment-form-url-field">Website</label>
																<input type="text" name="url" class="jp-carousel-comment-form-field jp-carousel-comment-form-text-field" id="jp-carousel-comment-form-url-field">
															</fieldset>
																											</div>
													<input type="submit" name="submit" class="jp-carousel-comment-form-button" id="jp-carousel-comment-form-button-submit" value="Post Comment">
												</div>
											</form>
																											</div>
													</div>
						<div class="jp-carousel-image-meta">
							<div class="jp-carousel-title-and-caption">
								<div class="jp-carousel-photo-info">
									<h3 class="jp-carousel-caption" itemprop="caption description"></h3>
								</div>

								<div class="jp-carousel-photo-description"></div>
							</div>
							<ul class="jp-carousel-image-exif" style="display: none;"></ul>
							<a class="jp-carousel-image-download" target="_blank" style="display: none;">
								<svg width="25" height="24" viewBox="0 0 25 24" fill="none" xmlns="http://www.w3.org/2000/svg">
									<mask id="mask0" mask-type="alpha" maskUnits="userSpaceOnUse" x="3" y="3" width="19" height="18">
										<path fill-rule="evenodd" clip-rule="evenodd" d="M5.84615 5V19H19.7775V12H21.7677V19C21.7677 20.1 20.8721 21 19.7775 21H5.84615C4.74159 21 3.85596 20.1 3.85596 19V5C3.85596 3.9 4.74159 3 5.84615 3H12.8118V5H5.84615ZM14.802 5V3H21.7677V10H19.7775V6.41L9.99569 16.24L8.59261 14.83L18.3744 5H14.802Z" fill="white"></path>
									</mask>
									<g mask="url(#mask0)">
										<rect x="0.870605" width="23.8823" height="24" fill="#FFFFFF"></rect>
									</g>
								</svg>
								<span class="jp-carousel-download-text"></span>
							</a>
							<div class="jp-carousel-image-map" style="display: none;"></div>
						</div>
					</div>
				</div>
			</div>
		</div>

		</div>
		
	<script type="text/javascript">
		window.WPCOM_sharing_counts = {"https:\/\/blog.smittytone.net\/2021\/02\/05\/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd\/":2258};
	</script>
							
<link rel="stylesheet" id="all-css-0-2" href="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(5)" type="text/css" media="all">
<script id="coblocks-lightbox-js-extra">
var coblocksLigthboxData = {"closeLabel":"Close Gallery","leftLabel":"Previous","rightLabel":"Next"};
</script>
<script id="jetpack-carousel-js-extra">
var jetpackSwiperLibraryPath = {"url":"\/wp-content\/mu-plugins\/carousel\/swiper-bundle.js"};
var jetpackCarouselStrings = {"widths":[370,700,1000,1200,1400,2000],"is_logged_in":"","lang":"en","ajaxurl":"https:\/\/blog.smittytone.net\/wp-admin\/admin-ajax.php","nonce":"11b486c228","display_exif":"1","display_comments":"1","display_geo":"1","single_image_gallery":"1","single_image_gallery_media_file":"","background_color":"black","comment":"Comment","post_comment":"Post Comment","write_comment":"Write a Comment...","loading_comments":"Loading Comments...","download_original":"View full size <span class=\"photo-size\">{0}<span class=\"photo-size-times\">\u00d7<\/span>{1}<\/span>","no_comment_text":"Please be sure to submit some text with your comment.","no_comment_email":"Please provide an email address to comment.","no_comment_author":"Please provide your name to comment.","comment_post_error":"Sorry, but there was an error posting your comment. Please try again later.","comment_approved":"Your comment was approved.","comment_unapproved":"Your comment is in moderation.","camera":"Camera","aperture":"Aperture","shutter_speed":"Shutter Speed","focal_length":"Focal Length","copyright":"Copyright","comment_registration":"0","require_name_email":"1","login_url":"https:\/\/smittytone.wordpress.com\/wp-login.php?redirect_to=https%3A%2F%2Fblog.smittytone.net%2F2021%2F02%2F05%2Fhow-to-debug-a-raspberry-pi-pico-with-a-mac-swd%2F","blog_id":"11065590","meta_data":["camera","aperture","shutter_speed","focal_length","copyright"],"stats_query_args":"blog=11065590&v=wpcom&tz=0&user_id=0&subd=smittytone","is_public":"1"};
</script>
<script crossorigin="anonymous" type="text/javascript" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(6)"></script>
<script id="crowdsignal-rating-js-before">
<!--//--><![CDATA[//><!--
PDRTJS_settings_1209223_post_2258={"id":1209223,"unique_id":"wp-post-2258","title":"How%20to%20debug%20a%20Raspberry%20Pi%20Pico%20with%20a%20Mac%2C%20SWD%20and%26%238230%3B%20another%26nbsp%3BPico","permalink":"https:\/\/blog.smittytone.net\/2021\/02\/05\/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd\/","item_id":"_post_2258"}; if ( typeof PDRTJS_RATING !== 'undefined' ){if ( typeof PDRTJS_1209223_post_2258 == 'undefined' ){PDRTJS_1209223_post_2258 = new PDRTJS_RATING( PDRTJS_settings_1209223_post_2258 );}}
//--><!]]>
</script>
<script src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/rating.js" id="crowdsignal-rating-js"></script>
<script id="sharing-js-js-extra">
var sharing_js_options = {"lang":"en","counts":"1","is_stats_active":"1"};
</script>
<script async="true" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/count.json"></script><script async="true" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/saved_resource(7)"></script><script crossorigin="anonymous" type="text/javascript" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/sharing.js"></script>
<script type="text/javascript">
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-twitter' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-twitter' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomtwitter', 'menubar=1,resizable=1,width=600,height=350' );
						return false;
					}
				} );
			} )();
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-tumblr' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-tumblr' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomtumblr', 'menubar=1,resizable=1,width=450,height=450' );
						return false;
					}
				} );
			} )();
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-linkedin' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-linkedin' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomlinkedin', 'menubar=1,resizable=1,width=580,height=450' );
						return false;
					}
				} );
			} )();
var windowOpen;
			( function () {
				function matches( el, sel ) {
					return !! (
						el.matches && el.matches( sel ) ||
						el.msMatchesSelector && el.msMatchesSelector( sel )
					);
				}

				document.body.addEventListener( 'click', function ( event ) {
					if ( ! event.target ) {
						return;
					}

					var el;
					if ( matches( event.target, 'a.share-facebook' ) ) {
						el = event.target;
					} else if ( event.target.parentNode && matches( event.target.parentNode, 'a.share-facebook' ) ) {
						el = event.target.parentNode;
					}

					if ( el ) {
						event.preventDefault();

						// If there's another sharing window open, close it.
						if ( typeof windowOpen !== 'undefined' ) {
							windowOpen.close();
						}
						windowOpen = window.open( el.getAttribute( 'href' ), 'wpcomfacebook', 'menubar=1,resizable=1,width=600,height=400' );
						return false;
					}
				} );
			} )();
</script>
<script type="text/javascript">
// <![CDATA[
(function() {
try{
  if ( window.external &&'msIsSiteMode' in window.external) {
    if (window.external.msIsSiteMode()) {
      var jl = document.createElement('script');
      jl.type='text/javascript';
      jl.async=true;
      jl.src='/wp-content/plugins/ie-sitemode/custom-jumplist.php';
      var s = document.getElementsByTagName('script')[0];
      s.parentNode.insertBefore(jl, s);
    }
  }
}catch(e){}
})();
// ]]>
</script>	<iframe src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/master.html" scrolling="no" id="likes-master" name="likes-master" style="display:none;"></iframe>
	<div id="likes-other-gravatars">
		<div class="likes-text">
			<span>%d</span> bloggers like this:		</div>
		<ul class="wpl-avatars sd-like-gravatars"></ul>
	</div>
	
		<script src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/w.js" defer=""></script> <script type="text/javascript">
_tkq = window._tkq || [];
_stq = window._stq || [];
_tkq.push(['storeContext', {'blog_id':'11065590','blog_tz':'0','user_lang':'en','blog_lang':'en','user_id':'0'}]);
_stq.push(['view', {'blog':'11065590','v':'wpcom','tz':'0','user_id':'0','post':'2258','subd':'smittytone'}]);
_stq.push(['extra', {'crypt':'UE40eW5QN0p8M2Y/RE1TaVhzUzFMbjdWNHpwZGhTayxPSUFCMGNrd29+Smw0TDhnZmRTK0hlRi9QSGh6bi9GXVhBJWIlZlR5U1JMLU8/MkNtblkvY1dzK3YrWW16SXlfX2E4SWFOK25BfFZLYlslNCtuP19fb0tHaDkzcThPRSZdVmEsbldTUDF6VW5qYTdCVj1UMlo9eFhKRWZfbEtsemEzW3RFK1ssaXpfQkUxeFlzRjlbZFQyVldxMEpRSmE/cW8xWDEuWH5kWWVEaUFYa180L1NkM1FXNW5rV3ctQkRGdDVSNF9rdk0vLWhiY0Q9cXg/LExqMXJMK2ktalBIVjl6V1NScUQzd3ZoW3hEaW9HfHx3RHYlP11FVVljd1IuXVkwaEI1cW1HJS02aS5xYm8wMEZw'}]);
_stq.push([ 'clickTrackerInit', '11065590', '2258' ]);
	</script>
<noscript><img src="https://pixel.wp.com/b.gif?v=noscript" style="height:1px;width:1px;overflow:hidden;position:absolute;bottom:1px;" alt="" /></noscript>
<script>
if ( 'object' === typeof wpcom_mobile_user_agent_info ) {

	wpcom_mobile_user_agent_info.init();
	var mobileStatsQueryString = "";
	
	if( false !== wpcom_mobile_user_agent_info.matchedPlatformName )
		mobileStatsQueryString += "&x_" + 'mobile_platforms' + '=' + wpcom_mobile_user_agent_info.matchedPlatformName;
	
	if( false !== wpcom_mobile_user_agent_info.matchedUserAgentName )
		mobileStatsQueryString += "&x_" + 'mobile_devices' + '=' + wpcom_mobile_user_agent_info.matchedUserAgentName;
	
	if( wpcom_mobile_user_agent_info.isIPad() )
		mobileStatsQueryString += "&x_" + 'ipad_views' + '=' + 'views';

	if( "" != mobileStatsQueryString ) {
		new Image().src = document.location.protocol + '//pixel.wp.com/g.gif?v=wpcom-no-pv' + mobileStatsQueryString + '&baba=' + Math.random();
	}
	
}
</script>
<style>img#wpstats {
			position: absolute !important;
			clip: rect(0, 0, 0, 0);
			padding: 0 !important;
			border: 0 !important;
			height: 0 !important;
			width: 0 !important;
			overflow: hidden;
		}</style><img src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/g.gif" alt=":)" id="wpstats"><div id="sharing_email" style="display: none;">
		<form action="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/" method="post">
			<label for="target_email">Send to Email Address</label>
			<input type="email" name="target_email" id="target_email" value="">

			
				<label for="source_name">Your Name</label>
				<input type="text" name="source_name" id="source_name" value="">

				<label for="source_email">Your Email Address</label>
				<input type="email" name="source_email" id="source_email" value="">

						<input type="text" id="jetpack-source_f_name" name="source_f_name" class="input" value="" size="25" autocomplete="off" title="This field is for validation and should not be changed">
			
			<div class="g-recaptcha" data-sitekey="6LcmyE0UAAAAALID28yVNg7pFCodGaArJzHitez_" data-theme="light" data-type="image" data-tabindex="0" data-lazy="true" data-url="https://www.google.com/recaptcha/api.js?hl=en"></div>
			
			<img style="float: right; display: none" class="loading" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/loading.gif" alt="loading" width="16" height="16" scale="0">
			<input type="submit" value="Send Email" class="sharing_send">
			<a rel="nofollow" href="https://blog.smittytone.net/2021/02/05/how-to-debug-a-raspberry-pi-pico-with-a-mac-swd/#cancel" class="sharing_cancel" role="button">Cancel</a>

			<div class="errors errors-1" style="display: none;">
				Post was not sent - check your email addresses!			</div>

			<div class="errors errors-2" style="display: none;">
				Email check failed, please try again			</div>

			<div class="errors errors-3" style="display: none;">
				Sorry, your blog cannot share posts by email.			</div>
		</form>
	</div><iframe scrolling="no" id="wpcom_remote_login_key" src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/remote-login.html" style="display: none;"></iframe><script src="./How to debug a Raspberry Pi Pico with a Mac, SWD and… another Pico _ smittytone messes with micros_files/actionbar.js" defer=""></script></body></html>
