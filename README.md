# Game Closure DevKit Plugin: InMobi

This plugin allows you to collect analytics using the [InMobi](http://www.inmobi.com/) toolkit. Both iOS and Android targets are supported.

## Usage

Install the plugin with `basil install inmobi`.

Include it in the `manifest.json` file under the "addons" section for your game:

~~~
"addons": [
	"inmobi"
],
~~~

Under the Android section, you can configure the InMobi plugin:

~~~
	"android": {
		"versionCode": 1,
		"icons": {
			"36": "resources/icons/android36.png",
			"48": "resources/icons/android48.png",
			"72": "resources/icons/android72.png",
			"96": "resources/icons/android96.png"
		},
		"inMobiKey": "4028cba631d63df10131e1d4650600cd",
	}
~~~

~~~
	"ios": {
		"bundleID": "mmp",
		"appleID": "568975017",
		"version": "1.0.3",
		"icons": {
			"57": "resources/images/promo/icon57.png",
			"72": "resources/images/promo/icon72.png",
			"114": "resources/images/promo/icon114.png",
			"144": "resources/images/promo/icon144.png"
		},
		"inMobiKey": "4028cba631d63df10131e1d4650600cd",
	}
~~~

To use InMobi logging in your game, import the plugin at the top of Application.js, like so:

~~~
import plugins.inmobi.inmobi as inmobi;
~~~

Then send individual logs like this:

~~~
inmobi.track("myEvent", {
	"score": 999,
	"coins": 11,
	"isRandomParameter": true
});
~~~

## Testing

To test for successful integration, build your game:

~~~
basil debug native-android --clean --open
~~~

Then watch logcat:

~~~
adb logcat | grep inmobi
~~~

If InMobi is hooked up properly, you'll see something like this:

~~~
D/JS      ( 4673): LOG plugins.inmobi.inmobi {inmobi} track:  AppStart [object Object]
D/JS      ( 4673): LOG plugins.inmobi.inmobi {inmobi} track:  UpgradePriceGroup [object Object]
E/JS      ( 4673): {inmobi} {android} track - success: AppStart 
E/JS      ( 4673): {inmobi} {android} track - success: UpgradePriceGroup
~~~

(You'll see your own logs instead of AppStart and UpgradePriceGroup)

You can conclusively confirm events are going through on the InMobi website.

## Platform-specific notes

### Browsers

Nothing actually gets sent to InMobi in browsers, but you'll still see logs that look like this:

~~~
D/JS      ( 4673): LOG plugins.inmobi.inmobi {inmobi} track:  AppStart [object Object]
~~~

You can use these logs to implement tracking in your game.

### iOS

To use this plugin with iOS, you'll need to set up an InMobi account and add your InMobi key to the manifest (see Usage section, above).

### Android

To use this plugin with Android, you'll need to set up an InMobi account and add your InMobi key to the manifest (see Usage section, above).
