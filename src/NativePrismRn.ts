import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  multiply(a: number, b: number): number;
  multiply2(a: number, b: number): number;
}

export default TurboModuleRegistry.getEnforcing<Spec>('Prism-Rn');
