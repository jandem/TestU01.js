importScripts("testu01.test.js");

Module.print = function(s) {
    postMessage({output: s});
}

onmessage = function(e) {
    switch (e.data) {
      case "SmallCrush":
	Module._RunSmallCrushMathRandom();
	break;
      case "Crush":
	Module._RunCrushMathRandom();
	break;
      case "BigCrush":
	Module._RunBigCrushMathRandom();
	break;
      default:
        console.error("Received invalid value: " + e.data);
    }
    postMessage({done: true});
}
