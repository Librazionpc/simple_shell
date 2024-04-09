// SubscriptionScreen.js
import React, { useState } from 'react';
import { View, Text, TouchableOpacity } from 'react-native';
import subscriptionStyles from './styles/SubscriptionStyles';

const SubscriptionScreen = () => {
  const [selectedPlan, setSelectedPlan] = useState(null);

  const subscribe = () => {
    if (!selectedPlan) {
      alert('Please select a plan before subscribing.');
      return;
    }

    // Simulate the subscription process here
    alert(`Subscribed to ${selectedPlan} plan!`);
  };

  const renderPlan = (plan) => (
    <TouchableOpacity
      key={plan.title}
      style={subscriptionStyles.planContainer}
      onPress={() => setSelectedPlan(plan.title)}
    >
      <Text style={subscriptionStyles.planTitle}>{plan.title}</Text>
      <Text>{plan.description}</Text>
    </TouchableOpacity>
  );

  const subscriptionPlans = [
    {
      title: 'Basic Plan',
      description: 'Crop Management Features, Basic Pest Control, Limited Support',
    },
    {
      title: 'Standard Plan',
      description:
        'Full Crop Management Suite, Comprehensive Pest Control, Expert Consultation (Limited Hours), Basic Soil Testing',
    },
    {
      title: 'Premium Plan',
      description:
        'Advanced Crop Management and Optimization, Personalized Pest Control Strategies, Detailed Weather Insights and Forecasting, Priority Expert Consultation, Enhanced Soil Testing and Analysis, Access to Exclusive Webinars and Workshops',
    },
  ];

  return (
    <View style={subscriptionStyles.container}>
      <Text style={subscriptionStyles.title}>Choose a Subscription Plan</Text>
      {subscriptionPlans.map(renderPlan)}
      <TouchableOpacity style={subscriptionStyles.subscribeButton} onPress={subscribe}>
        <Text style={subscriptionStyles.buttonText}>Subscribe</Text>
      </TouchableOpacity>
    </View>
  );
};

export default SubscriptionScreen;
