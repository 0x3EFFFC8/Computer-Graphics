var canvas = document.getElementById("renderCanvas");

var startRenderLoop = function (engine, canvas) {
    engine.runRenderLoop(function () {
        if (sceneToRender && sceneToRender.activeCamera) {
            sceneToRender.render();
        }
    });
}

var engine = null;
var scene = null;
var sceneToRender = null;

var createDefaultEngine = function() {
    return new BABYLON.Engine(canvas, true, {
        preserveDrawingBuffer: true,
        stencil: true,
        disableWebGL2Support: false
    });
};

var createScene = function () {
    var scene = new BABYLON.Scene(engine);

    var camera = new BABYLON.ArcRotateCamera("camera", 
        BABYLON.Tools.ToRadians(90), 
        BABYLON.Tools.ToRadians(65), 
        10, 
        BABYLON.Vector3.Zero(), 
        scene
    );

    camera.attachControl(canvas, true);

    var light = new BABYLON.HemisphericLight("light", new BABYLON.Vector3(0, 1, 0), scene);
    light.intensity = 0.7;

    var castleMat = new BABYLON.StandardMaterial("castleMat", scene);
    castleMat.diffuseColor = new BABYLON.Color3(0.5, 0.5, 0.5);

    BABYLON.SceneLoader.ImportMeshAsync("", "https://0x3efffc8.github.io/test/Meshes/", "castle/castle.glb").then((result) => {
        result.meshes[1].material = castleMat;
        result.meshes[1].position = new BABYLON.Vector3(0, 0, 0);
        result.meshes[1].scaling = new BABYLON.Vector3(1, 1, 1);
    });

    var castleTowerMat = new BABYLON.StandardMaterial("castleTowerMat", scene);
    castleTowerMat.diffuseTexture = new BABYLON.Texture("https://0x3efffc8.github.io/test/Meshes/castleTower/castleTower.png", scene);

    BABYLON.SceneLoader.ImportMeshAsync("", "https://0x3efffc8.github.io/test/Meshes/", "castleTower/castleTower.glb").then((result) => {
        result.meshes[1].material = castleTowerMat;
        result.meshes[1].position = new BABYLON.Vector3(0, -145, 15);
        result.meshes[1].scaling = new BABYLON.Vector3(7, 7, 55);
    });

    var dragonMat = new BABYLON.StandardMaterial("dragonMat", scene);
    dragonMat.diffuseTexture = new BABYLON.Texture("https://0x3efffc8.github.io/test/Meshes/dragon/dragon.jpg", scene);

    BABYLON.SceneLoader.ImportMeshAsync("", "https://0x3efffc8.github.io/test/Meshes/", "dragon/dragon.glb").then((result) => {
        result.meshes[1].material = dragonMat;
        result.meshes[1].y = Math.PI;
        result.meshes[1].position = new BABYLON.Vector3(90, 180, 0);
        result.meshes[1].scaling = new BABYLON.Vector3(0.8, 0.8, 0.8);
    });
    
    return scene;
};

window.initFunction = async function() {
    var asyncEngineCreation = async function() {
        try {
            return createDefaultEngine();
        } catch(e) {
            console.log("the available createEngine function failed. Creating the default engine instead");
            return createDefaultEngine();
        }
    }

    window.engine = await asyncEngineCreation();
    if (!engine) throw 'engine should not be null.';
    startRenderLoop(engine, canvas);
    window.scene = createScene();
};

initFunction().then(() => {
    sceneToRender = scene;
});

window.addEventListener("resize", function () {
    engine.resize();
});