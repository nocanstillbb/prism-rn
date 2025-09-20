/**
 * @type {import('@react-native-community/cli-types').UserDependencyConfig}
        cxxModuleHeaderName: 'MyHeader', // CLI will include this header while linking.
 */
module.exports = {
  dependency: {
    platforms: {
      android: {
        sourceDir: 'android',
        cxxModuleCMakeListsPath: `CMakeLists.txt`, // This is relative to the sourceDir.
        cxxModuleCMakeListsModuleName: 'prism-rn', // This is the name of the CMake target.
      },
    },
  },
};
