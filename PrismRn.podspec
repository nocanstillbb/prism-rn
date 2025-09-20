require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "PrismRn"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.ios.deployment_target = '12.0'
  s.osx.deployment_target = '10.15'

  s.source       = { :git => "https://github.com/nocanstillbb/prism-rn.git", :tag => "#{s.version}" }

  s.source_files = "ios/**/*.{h,m,mm}", "cpp/**/*.{hpp,cpp,c,h}"

  # Use install_modules_dependencies helper to install the dependencies if React Native version >=0.71.0.
  # See https://github.com/facebook/react-native/blob/febf6b7f33fdb4904669f99d795eba4c0f95d7bf/scripts/cocoapods/new_architecture.rb#L79.
  if respond_to?(:install_modules_dependencies, true)
    install_modules_dependencies(s)
  else
    s.dependency "React-Core"
  end




  # copy header to lib dir
  s.script_phase = {
    :name => "Sync PrismRn Codegen",
    #:execution_position => :after_compile,
    :execution_position => :before_compile,
    :shell_path => "/bin/sh",
    :script => <<-SCRIPT
      echo "🔹 Syncing PrismRn codegen files.." >&2
  
      LIB_DIR="$PODS_TARGET_SRCROOT"
  
      APP_ROOT="$(dirname "$PODS_ROOT")/../.." 
      BUILD_ROOT="$(dirname "$PODS_ROOT")/build" 
  
      if [ -d "$BUILD_ROOT/generated/ios" ]; then
        GENERATED_DIR="$BUILD_ROOT/generated/ios"
      elif [ -d "$BUILD_ROOT/generated/ios" ]; then
        GENERATED_DIR="$BUILD_ROOT/generated/ios"
      else
        echo "⚠️ No codegen directory found in $BUILD_ROOT/generated" >&2
        exit 0
      fi
  
      TARGET_DIR="$LIB_DIR/ios/generated/ios"
  
      echo "App codegen dir: $GENERATED_DIR" >&2
      echo "Library target dir: $TARGET_DIR" >&2
  
      mkdir -p "$TARGET_DIR"
      rsync -av  --include='*/' --include='*.hpp'  --include='*.h' --exclude='*' "$GENERATED_DIR/" "$TARGET_DIR/"
      echo "Codegen files synced" >&2
    SCRIPT
  }


end
