var InMobi = Class(function () {
	this.track = function (name, data) {
		logger.log("{inmobi} track: ", name, data);
		NATIVE && NATIVE.plugins && NATIVE.plugins.sendEvent &&
			NATIVE.plugins.sendEvent("InMobiPlugin", "track",
				JSON.stringify({ eventName: name, params: data }));
	};
});

exports = new InMobi();