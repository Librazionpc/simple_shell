// RegistrationScreen.js
import React, { useState } from 'react';
import { View, Text, TextInput, Button, ImageBackground, Alert, StyleSheet } from 'react-native';
import { useNavigation } from '@react-navigation/native';
import styles from './styles/RegistrationStyles';

const RegistrationScreen = () => {
  const [username, setUsername] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const navigation = useNavigation();

  const handleRegistration = () => {
    // Simulate registration process (replace this with API call in a real app)
    // After successful registration, navigate to the SubscriptionScreen
    // For now, we'll navigate immediately (you can replace this with your logic)
    navigation.navigate('Subscription');
  };

  return (
    <ImageBackground source={require('./assets/farm.jpg')} style={styles.backgroundImage}>
      <View style={styles.container}>
        <Text style={styles.title}>Registration Page</Text>
        <TextInput
          placeholder="Username"
          value={username}
          onChangeText={(text) => setUsername(text)}
          style={styles.input}
        />
        <TextInput
          placeholder="Email"
          value={email}
          onChangeText={(text) => setEmail(text)}
          style={styles.input}
        />
        <TextInput
          placeholder="Password"
          value={password}
          onChangeText={(text) => setPassword(text)}
          secureTextEntry
          style={styles.input}
        />
        <Button title="Register" onPress={handleRegistration} />
      </View>
    </ImageBackground>
  );
};

export default RegistrationScreen;
