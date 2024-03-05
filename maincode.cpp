  if(!(manager()->load(plugin) & PluginManager::LoadState::Loaded)) {
        Error{} << "Trade::AnySceneConverter::convertToFile(): cannot load the" << plugin << "plugin";
        return false;
    }

    const PluginManager::PluginMetadata* const metadata = manager()->metadata(plugin);
    CORRADE_INTERNAL_ASSERT(metadata);
    if(flags() & SceneConverterFlag::Verbose) {
        Debug d;
        d << "Trade::AnySceneConverter::convertToFile(): using" << plugin;
        if(plugin != metadata->name())
            d << "(provided by" << metadata->name() << Debug::nospace << ")";
    }
  return converter->convertToFile(mesh, filename);
}

void AnySceneConverter::doAbort() {
    _converter->abort();
    _converter = {};
}

bool AnySceneConverter::doBeginFile(const Containers::StringView filename) {
    CORRADE_INTERNAL_ASSERT(manager());
